/*
 * TimerExtended.cpp
 *
 * Created: 31/07/2014 20:54:26
 *  Author: Willyan
 */ 

/*
Date: 2014-07-09
Title: Timer libray
Autor: Willyan Sergio Fidelis
Type file: Header
--------------------------------------------Remarks --------------------------------------------
This libray is used to replace the Arduino Delay(long) function, that is incovenient many times,
becouse stop the program.
--------------------------------------------Remarks --------------------------------------------
*/

#include "Timer.h"
#include "Arduino.h"

//Timer Function
bool timer(long unsigned scanDelta, long unsigned target, long unsigned &actual)
{
	if (actual >= target)
	{
		actual = 0;
		return true;
	}
	else
	{
		actual = actual + scanDelta;
		return false;
	}
}

//Timer OnOff Function:
void timerOnOff(long unsigned scanDelta, long unsigned TimeOnTarget, long unsigned TimeOffTarget, long unsigned &actualOn, long unsigned &actualOff, bool &OnOffOut)
{
	if (OnOffOut)
	{
		if (timer(scanDelta, TimeOnTarget, actualOn) )
		{
			OnOffOut = 0;
			return;
		}
	}
	if (!OnOffOut)
	{
		if (timer(scanDelta, TimeOffTarget, actualOff) )
		{
			OnOffOut = 1;
			return;
		}
	}
}

//Get True Time function:
void getTrueTime(long unsigned scanDelta, int &actualTrueTime, int &lastTrueTime, bool trueTag)
{
	if (!trueTag)
	{
		actualTrueTime = 0;
	}
	if (trueTag)
	{
		actualTrueTime = actualTrueTime + scanDelta;
		lastTrueTime = actualTrueTime;
	}
	
}