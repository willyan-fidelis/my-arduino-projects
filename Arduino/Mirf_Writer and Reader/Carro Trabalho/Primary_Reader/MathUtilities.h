/*
 * InRange.h
 *
 * Created: 30/07/2014 23:32:34
 *  Author: Willyan
 */ 
#pragma once

#ifndef MATHUTILITIES_H_
#define MATHUTILITIES_H

bool InRangeCompare(int toBeTested, int toBeCompared, int tolerance);
bool InRange(int toBeTested, int upLevel, int lowLevel);
long unsigned longDelta(long unsigned &lastScan, long unsigned actualScan);
int scale(int totalValue, int totalPercent, int targetPercent);
int findBestSeqFrom2Lsts(int _size, int _tolerantetByItem, bool _tolIsPercent, int _minSamples, int _firstLst[], int _secLst[], int _bestSeq[]);//, unsigned int *_lpLstFirstElement, unsigned int *_lpLstSecondElement);
#endif /* INRANGE_H_ */
