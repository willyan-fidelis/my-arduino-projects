/*
 * InRange.cpp
 *
 * Created: 30/07/2014 23:34:49
 *  Author: Willyan
 */ 
#include "MathUtilities.h"

bool InRange(int toBeTested, int upLevel, int lowLevel)
{
	if ( ( upLevel >= toBeTested) & ( lowLevel <= toBeTested) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InRangeCompare(int toBeTested, int toBeCompared, int tolerance)
{
	
	if (InRange(toBeTested, toBeCompared + tolerance, toBeCompared - tolerance))
	{
		return true;
	} 
	else
	{
		return false;
	}
}

long unsigned longDelta(long unsigned &lastScan, long unsigned actualScan)
{
	long unsigned delta;
	
	if (actualScan >= lastScan)//Normal condition:
	{
		delta = actualScan - lastScan;
	}
	else if (actualScan < lastScan) //Overflow condition:
	{
		delta = (4294967295 - lastScan) + lastScan;
	}
	lastScan = actualScan;
	return delta;
}