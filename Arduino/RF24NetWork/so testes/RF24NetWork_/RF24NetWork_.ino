#include "RF24NetWork.h"  //Local header
#include <SPI.h>
#include "Mirf.h"
//#include <nRF24L01.h>
//#include <MirfHardwareSpiDriver.h>
#include <MathUtilities.h>
#include <Timer.h>
#include <avr/wdt.h> //Include watchdog timer

struct DataToComunicatio {
  int Speed[25];
  byte HS;
  int Position;
};

DataToComunicatio * RF24Data;
byte * ptrbyte;

NR24NetWork NR24Node(SLAVE_MODE, (byte*&)RF24Data, sizeof(DataToComunicatio) );

void setup()
{
  Serial.begin(9600);
  
  
  //NR24NetWork NR24Node(SLAVE_MODE,(byte*&) RF24Data, sizeof(DataToComunicatio) );
  //Serial.println((int)RF24Data);
  //RF24Data->HS = 51;
  //Serial.println(RF24Data->HS);
  //NR24Node.setDeviceMode(READER_MODE);
}

void loop()
{
  
  //----------- Mode Selection -----------
  if (Serial.available() )
  {
  while (Serial.available() > 0)
  {
     char incomingChar = Serial.read();
     if (incomingChar == 'w')
     {
       RF24Data->HS = 27;
       NR24Node.setDeviceMode(WRITER_MODE);
       //Serial.println(RF24Data->HS);
       NR24Node.write(78);
     }
     if (incomingChar == 'r')
     {
       NR24Node.setDeviceMode(READER_MODE);
       //while(true)
       //{
       RF24Data->HS = 0;
       NR24Node.read();
       Serial.println(RF24Data->HS);
       //}
     }
     if (incomingChar == 'm')
     {
       NR24Node.setDeviceMode(MASTER_MODE);
     }
     if (incomingChar == 's')
     {
       NR24Node.setDeviceMode(SLAVE_MODE);
     }
  }
  }
  //----------- Mode Selection -----------
  
}
