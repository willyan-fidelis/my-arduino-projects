/*
 * TimeBsdCode.cpp
 *
 * Created: 19/08/2014 01:27:49
 *  Author: Willyan
 */ 

#include "TimeBsdCode.h"
#include "Arduino.h"
#include "MathUtilities.h"
#include "IOUtilities.h"

TimeBsdCode::TimeBsdCode(long _hz)
{
	Serial.begin(9600);
	m_code.hz = _hz;
	m_inputIsInverted = 1;
	m_maxSize = 100;
	m_code.pulses = (TTimeBsdCodeLogicValues*)::malloc(sizeof(TTimeBsdCodeLogicValues)*m_maxSize);
}

bool TimeBsdCode::compareCodes(TimeBsdCode &_IRToCompare)
{
	int range = 200;
	bool result;
	int	 checkfor;
	
	//Serial.print("First code size: ");Serial.println(_IRCode1.size, DEC);
	//Serial.print("Second code size: ");Serial.println(_IRCode2.size, DEC);
	
	//Check if the code to be compared is teached:
	if (!_IRToCompare.m_code.stTeached)
	{
		Serial.println("The code is different!");
		return false;
	}
	
	//Check who is the bigger size --->
	if (m_code.size > _IRToCompare.m_code.size)
	{
		//Serial.println("Size: The first code is bigger than second!");
		checkfor = _IRToCompare.m_code.size;
	}
	if (m_code.size < _IRToCompare.m_code.size)
	{
		//Serial.println("Size: The second code is bigger than first!");
		checkfor = m_code.size;
	}
	if (m_code.size == _IRToCompare.m_code.size)
	{
		//Serial.println("Size: Both code have same size!");
		
		checkfor = _IRToCompare.m_code.size;
	}
	//Check who is the bigger size <---
	result = 1;
	for (int i = 0; i < checkfor; i++)
	{
		
		//Compare if true time is the same or near:
		if (InRangeCompare(_IRToCompare.m_code.pulses[i].highValue, m_code.pulses[i].highValue, range) )
		//if ( ( (_IRCode1.pulses[i][0] + range) > _IRCode2.pulses[i][0]) & ( (_IRCode1.pulses[i][0] - range) < _IRCode2.pulses[i][0]) )
		{
		}
		else
		{
			//Serial.print("The following code is different(true time): "); Serial.println(i, DEC);
			result = 0;
		}
		//Compare if false time is the same or near:
		if (InRangeCompare(_IRToCompare.m_code.pulses[i].lowValue, m_code.pulses[i].lowValue, range) )
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

void TimeBsdCode::play(int _outputNO)
{
	if (m_code.stTeached)
	{
		for (int i = 0; i < m_code.size; i++)
		{
			pulse(m_code.pulses[i].highValue, _outputNO, m_code.hz);
			delayMicroseconds(m_code.pulses[i].lowValue);
		}
		
		Serial.println("Code played successfully!");
	}
	else
	{
		Serial.println("No code played!");
	}
}

void TimeBsdCode::pulse(long _microsecs, int _outputNO, long _hz)
{
	int dutyCyle;
	int fullWave;
	dutyCyle = (int)((1000000/_hz) - 6)/2;
	//dutyCyle = (int)((1000)/38 - 6)/2;
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

void TimeBsdCode::printCode()
{
	Serial.println("------------------ Report ------------------");
	Serial.println("General information:");
	Serial.print("HZ:");Serial.println(m_code.hz, DEC);
	Serial.println("Codes information:");
	
	if (m_code.stTeached)
	{
		Serial.print("Codes captured: ");Serial.println(m_code.size, DEC);
		for (int i = 0; i < m_code.size; i++)
		{
			//Serial.println("------------------");
			//Serial.print("For ID: ");		Serial.println(i, DEC);
			//Serial.print("True time: ");	Serial.println(m_code.pulses[i].highValue, DEC);
			//Serial.print("False time: ");	Serial.println(m_code.pulses[i].lowValue, DEC);
			Serial.print("myCode.m_code.pulses[");Serial.print(i, DEC);Serial.print("].highValue = ");Serial.print(m_code.pulses[i].highValue, DEC);Serial.println(";");
			Serial.print("myCode.m_code.pulses[");Serial.print(i, DEC);Serial.print("].lowValue = ");Serial.print(m_code.pulses[i].lowValue, DEC);Serial.println(";");
		}
	}
	else
	{
		Serial.println("No code teached yet! Please tech again!");
	}
	Serial.println("------------------ Report ------------------");
	delay(500);
}

bool TimeBsdCode::capture(int _PINDInputNO, bool _withTimeOut, int _arrayMaxSize)
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
	m_code.stTeached = 0;
	m_code.size = 0;
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
			m_code.stTeached = 0;
			m_code.size = 0;
			Serial.println("Maximum amount reached! The code is bigger than the maximum allowed! Try again!");
			return false;
		}
		//Test if it reached the maximum rates allowed		<-----------------------------------
		
		//While a "IRLogicLevelTrue" doesn't comes stay here.	------------------------------->
		if ( !( whileInput(IRLogicLevelTrue, _PINDInputNO, pulseMaxSize, m_code.pulses[currentIndex].highValue, resolution, true)) )
		{
			m_code.stTeached = 1;
			m_code.size = currentIndex;
			return true;
		}
		//While a "IRLogicLevelTrue" doesn't comes stay here.	<-------------------------------
		
		//While a "IRLogicLevelFalse" doesn't comes stay here.	------------------------------->
		if ( !( whileInput(IRLogicLevelFalse, _PINDInputNO, pulseMaxSize, m_code.pulses[currentIndex].lowValue, resolution, true)) )
		{
			m_code.stTeached = 1;
			m_code.size = currentIndex + 1;
			return true;
		}
		//While a "IRLogicLevelFalse" doesn't comes stay here.	<-------------------------------
		
		currentIndex++;
	}
	//Caption all signals cycle		<-----------------------------------------------------------
}

bool TimeBsdCode::teach(int _PINDInputNO)
{
	Serial.println("Start teaching. Please press the IR button!");
	if (capture(_PINDInputNO, true, m_maxSize))
	{
		Serial.println("Teached Successfully!");
	}
	else
	{
		Serial.println("Didn't Teach Successfully!");
	}
}

bool TimeBsdCode::compareCodes(int _PINDInputNO)
{
	TimeBsdCode IRToCompare(38);
	IRToCompare.capture(_PINDInputNO, false, m_maxSize);
	if (compareCodes(IRToCompare))
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
