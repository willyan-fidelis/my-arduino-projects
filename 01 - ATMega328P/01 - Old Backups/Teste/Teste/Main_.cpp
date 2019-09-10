#define F_CPU 16000000
#define ARDUINO 105
#include "Arduino.h"
#include "IR.h"
#include "RF.h"


//Pin numbers:
int btn1Pin = 6;
int ledGreenPin = 3;
int ledYellowPin = 4;
int ledRedPin = 5;
int IRLedEmiterPin = 13;
int IRLedPin = 2;
//Tags:
boolean btn1;
boolean ledGreen;
boolean ledYellow;
boolean ledRed;
boolean IRLed;
boolean IRLedEmiter;
//
boolean btn1ons;


//------------------------- My Project Tags/includes -------------------------	
#include "SPI.h"
#include "nRF24L01.h"
#include "RF24.h"			//http://maniacbug.github.io/RF24/classRF24.html#aa7e8523f86f9f8f20c274e0c89a5fd45
#include "MathUtilities.h"

#define SCKPin 13	//SKC - SPI Clock
#define MISOPin 12	//MISO - SPI Slave Data Output
#define MOSIPin 11	//MOSI - SPI Slave Data Input
#define CSPin 10	//CSN - SPI Chip Select
#define Ctrl_CELPin 9	//CE - Chip Enable activates TX or RX Mode.
#define IRQPin 2	//IRQ - Makable Interrupt Pin.					//interrupt 0	

byte data[20];

uint8_t abc;

//RF24 myRF24(Ctrl_CELPin, CSPin);
RF myRF();
//------------------------- My Project Tags/includes -------------------------	

void setup()
{
	
	Serial.begin(9600);
	pinMode(btn1Pin, INPUT);
	pinMode(IRLedPin, INPUT);
	pinMode(IRLedPin, INPUT);
	pinMode(ledGreenPin, OUTPUT);
	pinMode(ledYellowPin, OUTPUT);
	pinMode(ledRedPin, OUTPUT);
	pinMode(IRLedEmiterPin, OUTPUT);
	/*
	*/
	//------------------------- My Project Setup -------------------------
	/*
	Serial.begin(115200);
	Serial.println("Startup..");
	
	pinMode(SCKPin, OUTPUT);
	pinMode(MISOPin, INPUT);
	pinMode(MOSIPin, OUTPUT);
	pinMode(CSPin, OUTPUT);
	pinMode(Ctrl_CELPin, OUTPUT);
	//pinMode(IRQPin, INPUT_PULLUP);
	
	SPI.setBitOrder(MSBFIRST);
	SPI.setDataMode(SPI_MODE0);
	SPI.setClockDivider(SPI_CLOCK_DIV2);
	digitalWrite(Ctrl_CELPin, HIGH);
	digitalWrite(CSPin, HIGH);
	SPI.begin();
	
	//attachInterrupt(0, functionofTypeVoid, FALLING);
	digitalWrite(CSPin, LOW);
	data[0] = SPI.transfer(0x00);
	data[1] = SPI.transfer(0x00);
	Serial.println("Config: ");
	Serial.println(data[1], BIN);
	digitalWrite(CSPin, HIGH);
	*/
	//myRF24.begin();
	//myRF24.get_status();
	//------------------------- My Project Setup -------------------------
}	

void loop()
{	
	/*
	//Read inputs:
	btn1 = digitalRead(btn1Pin);
	btn2 = digitalRead(btn2Pin);
	btn3 = digitalRead(btn3Pin);
	IRLed = digitalRead(IRLedPin);
	*/
//------------------------- Main Program -------------------------		
	btn1 = digitalRead(btn1Pin);
	IRLed = digitalRead(IRLedPin);
	
	//if (true)//(btn1 & !btn1ons)
	//{
		//int array1[10] = {1,1,1,3,4,5,1,1,8,9};
		//int array2[10] = {8,9,1,3,4,5,1,1,1,1};
		//int array3[10];
		//int abc;
		////Serial.println("Porcentagem: "); Serial.println(scale(580, 100, 15), DEC);
		//Serial.println("Result: ");
		//for (int i = 0; i < findBestSeqFrom2Lsts(10, 20/*20%*/, 0, array1, array2, array3); i++)
		//{
			//Serial.println("Sequencia: "); Serial.println(array3[i], DEC);
		//}
	//}
	//btn1ons = btn1;
	//
	//ledGreen = !IRLed;
	//ledYellow = !IRLed;
	//ledRed = btn1;
	
	pinMode(15, INPUT);
	IRLedEmiter = digitalRead(15);
	
	//digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	//delay(1000);               // wait for a second
	//digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	//delay(1000);    // wait for a second
	//Serial.println("ok: ");
	
	digitalWrite(ledGreenPin, ledGreen);
	digitalWrite(ledYellowPin, ledYellow);
	digitalWrite(ledRedPin, ledRed);
	digitalWrite(IRLedEmiterPin, IRLedEmiter);
//------------------------- Main Program -------------------------	
	/*
	//Write outputs:
	digitalWrite(led1Pin, led1);
	digitalWrite(led2Pin, led2);
	digitalWrite(led3Pin, led3);
	digitalWrite(led4Pin, led4);
	//digitalWrite(IRLedEmiterPin, IRLedEmiter);
	*/
}
