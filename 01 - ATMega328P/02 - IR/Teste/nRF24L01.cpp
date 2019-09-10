/*
 * nRF24L01.cpp
 *
 * Created: 05/08/2014 01:28:39
 *  Author: Willyan
 */ 
#include "Arduino.h"
#include "SPI.h"
#include "pins_arduino.h"
#include "nRF24L01.h"

//SPI.begin();

 nRF24L01::nRF24L01()
{
	//Define:
	
	SPI.begin();
	SPI.setBitOrder(MSBFIRST);
}
