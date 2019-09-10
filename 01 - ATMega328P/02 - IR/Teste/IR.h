/*
Date: 2014-07-09
Title: Timer libray
Autor: Willyan Sergio Fidelis
Type file: Header
--------------------------------------------Remarks --------------------------------------------
This library is used to replace the Arduino Delay(long) function, that is inconvenient many times,
because stop the program.
--------------------------------------------Remarks --------------------------------------------
*/

#ifndef IR_H_
#define IR_H_

//#include "Arduino.h"

struct TIRCode{bool stTeached; int khz; int size; unsigned int pulses[100][2]; };

class IR
{
	public:
	//Public methods:
	IR(int khz);
	bool teach(int PINDInputNO);
	void play(int _outputNO);
	void printIRCode();// = 0; //Must be implemented
	bool compareIRCodes(IR &IRToCompare);
	bool compareIRCodes(int PINDInputNO);
	//Public members:
	TIRCode m_IRCode;
	bool m_inputIsInverted;
	
	private:
	//Private methods:
	void pulseIR(long microsecs, int _outputNO, int khz);
	bool capture(int PINDInputNO, bool withTimeOut);
};

class IRExpert : IR
{
	public:
	IRExpert(IR &IRRef);
	//virtual bool compareIRCodes(IR &IRToCompare);
};

#endif
