#define F_CPU 16000000
#define ARDUINO 105
#include "Arduino.h"
#include "IR.h"


//Pin numbers:
int btn1Pin = 9;
int btn2Pin = 3;
int btn3Pin = 4;
int led1Pin = 5;
int led2Pin = 6;
int led3Pin = 7;
int led4Pin = 8;
int IRLedPin = 2;
int IRLedEmiterPin = 13;
//Tags:
boolean btn1;
boolean btn2;
boolean btn3;
boolean led1;
boolean led2;
boolean led3;
boolean led4;
boolean IRLed;
boolean IRLedEmiter;
//
boolean btn1ons;
boolean btn2ons;
boolean btn3ons;
boolean btn2btn3ons;


IR myIR(38);
//IR myIR2(38);


void setup()
{
	Serial.begin(9600);
	pinMode(btn1Pin, INPUT);
	pinMode(btn2Pin, INPUT);
	pinMode(btn3Pin, INPUT);
	pinMode(IRLedPin, INPUT);
	pinMode(led1Pin, OUTPUT);
	pinMode(led2Pin, OUTPUT);
	pinMode(led3Pin, OUTPUT);
	pinMode(led4Pin, OUTPUT);
	pinMode(IRLedEmiterPin, OUTPUT);
}	

void loop()
{	
	//Read inputs:
	btn1 = digitalRead(btn1Pin);
	btn2 = digitalRead(btn2Pin);
	btn3 = digitalRead(btn3Pin);
	IRLed = digitalRead(IRLedPin);
//------------------------- Main Program -------------------------		
	if (btn1 & !btn1ons)
	{
		//Serial.println("Please teach first code!");
		myIR.m_inputIsInverted = 0;
		myIR.teach(IRLedPin);
		//delay(500);
		//Serial.println("Please teach second code!");
		//myIR2.teach(IRLedPin);

		//myIR.compareIRCodes(myIR2);
	}
	btn1ons = btn1;
	
	if (btn2 & !btn2ons)
	{
		myIR.play(IRLedEmiterPin);
	}
	btn2ons = btn2;
	
	if (btn3 & !btn3ons)
	{
		 //myIR2.play(IRLedEmiterPin);
		 myIR.printIRCode();
	}
	btn3ons = btn3;
	
	if (btn2 & btn3)
	{
		myIR.printIRCode();
	}
	
	/*
	if (myIR.m_IRCode.stTeached)
	{
		Serial.println("Waiting..");
		if (myIR.compareIRCodes(IRLedPin))
		{
			led1 = !led1;
		}
		
	}
	
	led2 = !digitalRead(IRLedPin);
	*/
//------------------------- Main Program -------------------------	
	//Write outputs:
	digitalWrite(led1Pin, led1);
	digitalWrite(led2Pin, led2);
	digitalWrite(led3Pin, led3);
	digitalWrite(led4Pin, led4);
	//digitalWrite(IRLedEmiterPin, IRLedEmiter);
}
