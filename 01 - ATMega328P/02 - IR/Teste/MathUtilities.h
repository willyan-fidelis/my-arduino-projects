/*
 * InRange.h
 *
 * Created: 30/07/2014 23:32:34
 *  Author: Willyan
 */ 
#pragma once

#ifndef MATHUTILITIES_H_
#define MATHUTILITIES_H_

bool InRangeCompare(int toBeTested, int toBeCompared, int tolerance);
bool InRange(int toBeTested, int upLevel, int lowLevel);
long unsigned longDelta(long unsigned &lastScan, long unsigned actualScan);


#endif /* INRANGE_H_ */