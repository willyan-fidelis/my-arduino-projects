/*
Date: 2014-07-09
Title: Timer libray
Autor: Willyan Sergio Fidelis
Type file: Header
--------------------------------------------Remarks --------------------------------------------

--------------------------------------------Remarks --------------------------------------------
*/

#ifndef IR_H_
#define IR_H_

//#include "Arduino.h"
#include "TimeBsdCode.h"

class IR:TimeBsdCode
{
	public:
	IR(long _i32kHz);
	virtual ~IR() {}
		
	//Public methods:
	virtual bool teach(int _PINDInputNO);
	virtual void play(int _outputNO);
	bool abc();
};
#endif
