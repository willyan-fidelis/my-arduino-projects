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

//Class Timer:
class Timer
{
	public:
	Timer();
	void start();
	void start(long unsigned _presetTime);
	void stop();
	//void pause();
	//void unpause();
	bool done();
	bool stRunning();
	//bool stPaused();
	long unsigned actulTime;
	long unsigned presetTime;
	private:
	bool m_stRunning;
	long unsigned lastScan;
	long unsigned delta;
	//bool m_stPaused;

};

//Free functions:
bool timer(long unsigned scanDelta, long unsigned target, long unsigned &actual);
void timerOnOff(long unsigned scanDelta, long unsigned TimeOnTarget, long unsigned TimeOffTarget, long unsigned &actualOn, long unsigned &actualOff, bool &OnOffOut);
void getTrueTime(long unsigned scanDelta, int &actualTrueTime, int &lastTrueTime, bool trueTag);
#endif
