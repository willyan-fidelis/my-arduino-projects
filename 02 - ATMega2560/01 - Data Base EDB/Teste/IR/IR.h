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
	//IR();
	virtual bool teach(int _PINDInputNO);
	void play(int _outputNO);
	void printIRCode();// = 0; //Must be implemented
	bool compareIRCodes(IR &_IRToCompare);
	bool compareIRCodes(int _PINDInputNO);
	bool save(char nameID[10]);
	bool recover(char nameID[10]);
	//Public members:
	TIRCode m_IRCode;
	bool m_inputIsInverted;
	
	protected:
	//Private methods:
	void pulseIR(long _microsecs, int _outputNO, int _khz);
	bool capture(int _PINDInputNO, bool _withTimeOut, int _arrayMaxSize);
};

class IRExpert : IR
{
	public:
	//Como herdar o contructor aki!
	IRExpert(IR &IRRef);
	//virtual bool compareIRCodes(IR &IRToCompare);
};

#endif
