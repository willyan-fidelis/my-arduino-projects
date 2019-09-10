/*
 * IR.cpp
 *
 * Created: 26/07/2014 01:20:26
 *  Author: Willyan
 */ 

#include "IR.h"
#include "Arduino.h"
#include "MathUtilities.h"
#include "IOUtilities.h"

IR::IR(int _khz)
{
	Serial.begin(9600);
	m_IRCode.khz = _khz;
	m_inputIsInverted = 1;
}

bool IR::compareIRCodes(IR &_IRToCompare)
{
	int range = 200;
	bool result;
	int	 checkfor;
	
	//Serial.print("First code size: ");Serial.println(_IRCode1.size, DEC);
	//Serial.print("Second code size: ");Serial.println(_IRCode2.size, DEC);
	
	//Check if the code to be compared is teached:
	if (!_IRToCompare.m_IRCode.stTeached)
	{
		Serial.println("The code is different!");
		return false;
	}
	
	//Check who is the bigger size --->
	if (m_IRCode.size > _IRToCompare.m_IRCode.size)
	{
		//Serial.println("Size: The first code is bigger than second!");
		checkfor = _IRToCompare.m_IRCode.size;
	} 
	if (m_IRCode.size < _IRToCompare.m_IRCode.size)
	{
		//Serial.println("Size: The second code is bigger than first!");
		checkfor = m_IRCode.size;
	}
	if (m_IRCode.size == _IRToCompare.m_IRCode.size)
	{
		//Serial.println("Size: Both code have same size!");
		
		checkfor = _IRToCompare.m_IRCode.size;
	}
	//Check who is the bigger size <---
	result = 1;
	for (int i = 0; i < checkfor; i++)
	{
		
		//Compare if true time is the same or near:
		if (InRangeCompare(_IRToCompare.m_IRCode.pulses[i][0], m_IRCode.pulses[i][0], range) )
		//if ( ( (_IRCode1.pulses[i][0] + range) > _IRCode2.pulses[i][0]) & ( (_IRCode1.pulses[i][0] - range) < _IRCode2.pulses[i][0]) )
		{
		} 
		else
		{
			//Serial.print("The following code is different(true time): "); Serial.println(i, DEC);
			result = 0;
		}
		//Compare if false time is the same or near:
		if (InRangeCompare(_IRToCompare.m_IRCode.pulses[i][1], m_IRCode.pulses[i][1], range) )
		//if ( ( (_IRCode1.pulses[i][1] + range) > _IRCode2.pulses[i][1]) & ( (_IRCode1.pulses[i][1] - range) < _IRCode2.pulses[i][1]) )
		{
		}
		else
		{
			//Serial.print("The following code is different(false time): "); Serial.println(i, DEC);
			result = 0;
		}
	}
	
	//Print the final result:
	//Serial.println("------------------ Final Result ------------------");
	if (result == 1)
	{
		Serial.println("The code is the same!");
		return true;
	} 
	else
	{
		Serial.println("The code is different!");
		return false;
	}
}

void IR::play(int _outputNO)
{
	if (m_IRCode.stTeached)
	{ 
		for (int i = 0; i < m_IRCode.size; i++)
		{
			pulseIR(m_IRCode.pulses[i][0], _outputNO, m_IRCode.khz);
			delayMicroseconds(m_IRCode.pulses[i][1]);			
		}
		
		Serial.println("Code played successfully!");
	} 
	else
	{
		Serial.println("No code played!");
	}
}

void IR::pulseIR(long _microsecs, int _outputNO, int _khz)
{
	int dutyCyle;
	int fullWave;
	dutyCyle = (int)((1000)/_khz - 6)/2;
	fullWave = (int)(dutyCyle*2)+6;
	
	while (_microsecs > 0)
	{
		// 38 kHz is about 13 microseconds high and 13 microseconds low
		digitalWrite(_outputNO, HIGH);  // this takes about 3 microseconds to happen
		delayMicroseconds(dutyCyle);         // hang out for 10 microseconds
		digitalWrite(_outputNO, LOW);   // this also takes about 3 microseconds
		delayMicroseconds(dutyCyle);         // hang out for 10 microseconds
		
		// so 26 microseconds altogether
		//microsecs -= 26;
		_microsecs -= fullWave;
	}
}

void IR::printIRCode()
{
	Serial.println("------------------ Report ------------------");
	Serial.println("General information:");
	Serial.print("kHZ:");Serial.println(m_IRCode.khz, DEC);
	Serial.print("Khz: ");Serial.println( m_IRCode.khz, DEC);
	Serial.println("Codes information:");
	
	if (m_IRCode.stTeached)
	{
		Serial.print("Codes captured: ");Serial.println(m_IRCode.size, DEC);
		for (int i = 0; i < m_IRCode.size; i++)
		{
			Serial.println("------------------");
			Serial.print("For ID: ");		Serial.println(i, DEC);
			Serial.print("True time: ");	Serial.println(m_IRCode.pulses[i][0], DEC);
			Serial.print("False time: ");	Serial.println(m_IRCode.pulses[i][1], DEC);
		}
	}
	else
	{
		Serial.println("No code teached yet! Please tech again!");
	}
	Serial.println("------------------ Report ------------------");
	delay(500);
}

bool IR::capture(int _PINDInputNO, bool _withTimeOut, int _arrayMaxSize)
{
	//Declare variables		--------------------------------------------------------->
	long unsigned currentPulse;			//Current pulse accumulator
	int currentIndex;					//Current Index
	//int _arrayMaxSize 100;			//Maximum size to be stored
	#define pulseMaxSize 65000			//Maximum Pulse size 65000
	#define resolution 30//20			//The resolution to verify a 
	bool IRLogicLevelTrue = !m_inputIsInverted;
	bool IRLogicLevelFalse = m_inputIsInverted;
	//Declare variables		<---------------------------------------------------------
	
	//Prepare to a new teach procedure		----------------------------------------->
	//currentPulse = 0;
	m_IRCode.stTeached = 0;
	m_IRCode.size = 0;
	currentIndex = 0;
	//Prepare to a new teach procedure		<---------------------------------------------------
	
	//Check if it is with or without timeout	----------------------------------------------->
	//Wait for a start signal. While a "IRLogicLevelFalse" doesn't comes stay here.	----------->
	if (_withTimeOut)
	{
		if ( !( whileInput(IRLogicLevelFalse, _PINDInputNO, 5000, currentPulse, resolution, true)) )
		{
			Serial.println("Time out. Try again!");
			return false;
		}
	} 
	else
	{
		whileInput(IRLogicLevelFalse, _PINDInputNO, 5000, currentPulse, resolution, false);
	}
	//Wait for a start signal. While a "IRLogicLevelFalse" doesn't comes stay here.	<-----------
	//Check if it is with or without timeout	<-----------------------------------------------
	
	//Caption all signals cycle		----------------------------------------------------------->
	while(1)
	{
		//Test if it reached the maximum rates allowed		----------------------------------->
		if ( currentIndex >= _arrayMaxSize )
		{
			m_IRCode.stTeached = 0;
			m_IRCode.size = 0;
			Serial.println("Maximum amount reached! The code is bigger than the maximum allowed! Try again!");
			return false;
		}
		//Test if it reached the maximum rates allowed		<-----------------------------------
		
		//While a "IRLogicLevelTrue" doesn't comes stay here.	------------------------------->
		if ( !( whileInput(IRLogicLevelTrue, _PINDInputNO, pulseMaxSize, m_IRCode.pulses[currentIndex][0], resolution, true)) )
		{
			m_IRCode.stTeached = 1;
			m_IRCode.size = currentIndex;
			return true;
		}
		//While a "IRLogicLevelTrue" doesn't comes stay here.	<-------------------------------
		
		//While a "IRLogicLevelFalse" doesn't comes stay here.	------------------------------->
		if ( !( whileInput(IRLogicLevelFalse, _PINDInputNO, pulseMaxSize, m_IRCode.pulses[currentIndex][1], resolution, true)) )
		{
			m_IRCode.stTeached = 1;
			m_IRCode.size = currentIndex + 1;
			return true;
		}
		//While a "IRLogicLevelFalse" doesn't comes stay here.	<-------------------------------
				
		currentIndex++;
	}
	//Caption all signals cycle		<-----------------------------------------------------------
}

bool IR::teach(int _PINDInputNO)
{
	Serial.println("Start teaching. Please press the IR button!");
	if (capture(_PINDInputNO, true, 100))
	{
		Serial.println("Teached Successfully!");
	} 
	else
	{
		Serial.println("Didn't Teach Successfully!");
	}
}

bool IR::compareIRCodes(int _PINDInputNO)
{
	IR IRToCompare(38);
	IRToCompare.capture(_PINDInputNO, false, 100);
	if (compareIRCodes(IRToCompare))
	{
		delay(200);
		return true;
	} 
	else
	{
		delay(200);
		return false;
	}
}
