/*
 * IOUtilities.cpp
 *
 * Created: 01/08/2014 23:52:08
 *  Author: Willyan
 */ 
#include "Arduino.h"
#include "IOUtilities.h"

bool whileInput(bool whileTrueOrFalse, int inputNO, int timeOut, unsigned int &acc, int timeResolutionMS, bool withTimeout)
{
	acc = 0;
	while
	(
	( (whileTrueOrFalse)  &&  (PIND & _BV(inputNO)) )
	||
	( (!whileTrueOrFalse) && !(PIND & _BV(inputNO)) )
	)
	{
		if (withTimeout)
		{
			if ( (acc >= timeOut) )
			{
				acc = 0;
				return false;
			}

			delayMicroseconds(timeResolutionMS);
			acc = acc + timeResolutionMS;
		}
	}
	return true;
}

bool whileInput(bool whileTrueOrFalse, int inputNO, unsigned long timeOut, unsigned long &acc, int timeResolutionMS, bool withTimeout)
{
	acc = 0;
	while
	(
	( (whileTrueOrFalse)  &&  (PIND & _BV(inputNO)) )
	||
	( (!whileTrueOrFalse) && !(PIND & _BV(inputNO)) )
	)
	{
		if (withTimeout)
		{
			if ( (acc >= (timeOut*1000)) )
			{
				acc = 0;
				return false;
			}

			delayMicroseconds(timeResolutionMS);
			acc = acc + (long)timeResolutionMS;
		}
	}
	return true;
}
