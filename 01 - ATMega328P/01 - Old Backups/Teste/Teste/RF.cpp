/*
 * RF.cpp
 *
 * Created: 11/08/2014 19:03:12
 *  Author: Willyan
 */ 

#include "RF.h"
#include "Arduino.h"
#include "MathUtilities.h"

RF::RF(int _i32MHz) : IR(_i32MHz)
{
	m_IRCode.stTeached = 0;
}		

 bool RF::teach(int _PINDInputNO, int _ctrlBtnInputNO)
{
	//IR::teach(_PINDInputNO);	//Take from mother class a same implamentation code
	IR IRToCompare1(38);
	IR IRToCompare2(38);
	
	Serial.println("Start teaching. Please press the IR button for the fist time!");
	if (capture(_PINDInputNO, true, 200))
	{
		Serial.println("Teached Successfully!");
	}
	else
	{
		Serial.println("Didn't Teach Successfully!");
	}
	
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
