/*
 * TimeBsdCode.h
 *
 * Created: 19/08/2014 01:27:32
 *  Author: Willyan
 */ 



#ifndef TIMEBSDCODE_H_
#define TIMEBSDCODE_H_

struct TTimeBsdCodeLogicValues {int unsigned highValue; int unsigned lowValue;};
struct TTimeBsdCode{bool stTeached; long hz; int size; TTimeBsdCodeLogicValues *pulses; };
	
class TimeBsdCode
{
	public:
	//Public methods:
	TimeBsdCode(long hz);
	//virtual ~TimeBsdCode() {}
		
	//TimeBsdCode();
	virtual bool teach(int _PINDInputNO);
	virtual void play(int _outputNO);
	void printCode();// = 0; //Must be implemented
	bool compareCodes(TimeBsdCode &_IRToCompare);
	bool compareCodes(int _PINDInputNO);
	//Public members:
	TTimeBsdCode m_code;
	bool m_inputIsInverted;
	int m_maxSize;
	
	protected:
	//Private methods:
	void pulse(long _microsecs, int _outputNO, long _hz);
	bool capture(int _PINDInputNO, bool _withTimeOut, int _arrayMaxSize);
};



#endif /* TIMEBSDCODE_H_ */