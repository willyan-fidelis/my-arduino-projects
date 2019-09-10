/*
 * RF.h
 *
 * Created: 11/08/2014 19:02:55
 *  Author: Willyan
 */ 

#include "TimeBsdCode.h"

#ifndef RF_H_
#define RF_H_

class RF:TimeBsdCode
{
	public:
	RF(int _i32MHz);
	
	//Public methods:
	virtual bool teach(int _PINDInputNO, int _ctrlBtnInputNO);
	bool abc();
};



#endif /* RF_H_ */