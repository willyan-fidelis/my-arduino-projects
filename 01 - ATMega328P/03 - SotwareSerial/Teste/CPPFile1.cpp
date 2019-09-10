/*
 * IncFile1.h
 *
 * Created: 20/07/2014 04:02:57
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

#ifndef TIMER_H
#define TIMER_H

//#include "Arduino.h"

class TIMER
{
	public:
	TIMER();
	void start();
	void stop();
	//void pause();
	//void unpause();
	bool done();
	bool stRunning();
	//bool stPaused();
	long unsigned delta;
	long unsigned actulTime;
	long unsigned presetTime;
	private:
	bool m_stRunning;
	//bool m_stPaused;

};

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

//#include "Timer.h"
//#include "Arduino.h"
//#include "WProgram.h"

TIMER::TIMER()
{
	presetTime = 1000;
}


void TIMER::start()
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

void TIMER::stop()
{
	actulTime = 0;
	m_stRunning = false;
}

bool TIMER::done()
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

bool TIMER::stRunning()
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

//Remove this:
//void main()
//{
	//return;
//}


#endif
