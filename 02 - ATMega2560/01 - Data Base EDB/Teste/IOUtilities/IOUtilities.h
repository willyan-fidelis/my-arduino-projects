/*
 * IOUtilities.h
 *
 * Created: 01/08/2014 23:52:35
 *  Author: Willyan
 */ 


#ifndef IOUTILITIES_H_
#define IOUTILITIES_H_


//************************************
// Method:    whileInput
// FullName:  whileInput
// Access:    public 
// Returns:   bool - Return False if a time out ocurried. Otherwise return true.
// Qualifier: 
// Parameter: bool whileTrueOrFalse
// Parameter: int timeOut
// Parameter: int acc
// Parameter: int inputNO
// Parameter: byte portID
//************************************
bool whileInput(bool whileTrueOrFalse, int inputNO, int timeOut, unsigned int &acc, int timeResolutionMS, bool withTimeout);

bool whileInput(bool whileTrueOrFalse, int inputNO, unsigned long timeOut, unsigned long &acc, int timeResolutionMS, bool withTimeout);


#endif /* IOUTILITIES_H_ */