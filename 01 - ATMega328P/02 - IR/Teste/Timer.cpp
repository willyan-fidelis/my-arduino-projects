/*
 * CPPFile1.cpp
 *
 * Created: 20/07/2014 03:56:36
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

Timer::Timer()
{
	presetTime = 1000;
}

void Timer::start()
{
	if (presetTime < actulTime)
	{
		actulTime = actulTime + delta;
		m_stRunning = true;
	}
	else
	{
		m_stRunning = false;
	}
	
}

void Timer::stop()
{
	actulTime = 0;
	m_stRunning = false;
}

bool Timer::done()
{
	if (presetTime >= actulTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Timer::stRunning()
{
	if (m_stRunning)
	{
		return true;
	}
	else
	{
		return false;
	}
}