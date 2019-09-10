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

IR::IR(long _i32kHz) : TimeBsdCode(_i32kHz*1000)
{
	Serial.begin(9600);
	m_code.hz = _i32kHz;
	m_inputIsInverted = 1;
}

void IR::play(int _outputNO)
{
	TimeBsdCode::play(_outputNO); //Take implementation from mother class
}

bool IR::teach(int _PINDInputNO)
{
	TimeBsdCode::teach( _PINDInputNO);//Take implementation from mother class
}