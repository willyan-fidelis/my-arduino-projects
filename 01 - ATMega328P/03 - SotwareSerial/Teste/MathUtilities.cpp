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

long unsigned longDelta(long unsigned &lastValue, long unsigned actualValue)
{
	long unsigned delta;
	
	if (actualValue >= lastValue)//Normal condition:
	{
		delta = actualValue - lastValue;
	}
	else if (actualValue < lastValue) //Overflow condition:
	{
		delta = (4294967295 - lastValue) + lastValue;
	}
	lastValue = actualValue;
	return delta;
}

int findBestSeqFrom2Lsts(int _size, int _tolerantetByItem, bool _tolIsPercent, int _minSamples, int _firstLst[], int _secLst[], int _bestSeq[])//, unsigned int *_lpLstFirstElement, unsigned int *_lpLstSecondElement)
{
	int tolValue;
	int bestSeqSamples = 0;
	int actSeqSamples = 0;	
	int bestPosFromFirstLst = 0;

	
	//Find out a better sequence from the lists:
	for (int i = 0; i < _size; i++) //--- go through the first list, item by item ---
	{
		for (int j = 0; j < _size; j++) //--- go through the second list, item by item ---
		{

			actSeqSamples = 0;
			int z = 0;
			for (int k = j; k < _size; k++) 
			{
				//Check if the tolerance is a percent or not:
				if (_tolIsPercent)
				{
					tolValue = scale(_firstLst[i + z], 100, _tolerantetByItem/*Tolerance from 20%*/);
				}
				else
				{
					tolValue = _tolerantetByItem;
				}
				
				if (InRangeCompare(_firstLst[i + z], _secLst[j + z], tolValue))
				{
					actSeqSamples++;
				
					if (actSeqSamples >= bestSeqSamples)
					{
						bestSeqSamples = actSeqSamples;
						bestPosFromFirstLst = i;
					} 
					else
					{
					}
				} 
				else
				{
					actSeqSamples = 0;
					break;
				}
				z++;
			}
		}
	}
	
	//check if there is a smaller samples at least:
	if (_minSamples > bestSeqSamples)
	{
		return 0;
	} 
	else
	{
		int x = 0;
		for (int i = bestPosFromFirstLst; i < bestPosFromFirstLst + bestSeqSamples; i++)
		{
			_bestSeq[x] = _firstLst[i];
			x++;
		}
		return bestSeqSamples;
	}
}

int scale(int _totalValue, int _totalPercent, int _targetPercent)
{
	return (_totalValue * _targetPercent)/_totalPercent;
}