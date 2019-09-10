/**
 * A Mirf example to test the latency between two Ardunio.
 *
 * Pins:
 * Hardware SPI:
 * MISO -> 12
 * MOSI -> 11
 * SCK -> 13
 *
 * Configurable:
 * CE -> 8
 * CSN -> 7
 *
 * Note: To see best case latency comment out all Serial.println
 * statements not displaying the result and load 
 * 'ping_server_interupt' on the server.
 */

#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <MathUtilities.h>
#include <Timer.h>
#include <avr/wdt.h> //Include watchdog timer

struct DataToComunicatio {
  int HS;
  int Speed;
  int Position;
  //byte GoToLeftOrRight;
  //byte GoToForwardOrBackward;
};

DataToComunicatio RFCtrl;
char incomingChar;
char stringToSend[5];
int TransmitOrReciveMode = 0;

Timer tmrChangeLedStatus;
Timer tmrFaultTMO;
int ledPin = 4;
boolean ledPinValue = 0;
unsigned long ValueToBeWrite = 77;
unsigned long ValueToBeRead = 0;

void setup(){
  wdt_enable(WDTO_2S); //Enable watchdog timer - 2 seconds
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  Mirf.csnPin = 10;
  Mirf.cePin = 9; 
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init(); 
  //Mirf.setRADDR((byte *)"clie1"); //Configure reciving address. 
  //Mirf.setTADDR((byte *)"serv1");
  Mirf.payload = sizeof(RFCtrl);   
  Mirf.config(); 
  Serial.println("Setupping... "); 
  
  
}

void loop()
{
  //----------------- Blink ----------------------
  tmrChangeLedStatus.start(30);
  if (tmrChangeLedStatus.done())
  {
    tmrChangeLedStatus.stop();
    ledPinValue = !ledPinValue;
    if (ledPinValue)
    {analogWrite(ledPin, 130);}//0 - 255 (130 is the smaller value to the LED)
    else
    {analogWrite(ledPin, 0);}
    //digitalWrite(ledPin, ledPinValue); 
  }
  //----------------- Blink ----------------------
  
  
  
  
  
  //----------- Serial Mode Selection -----------
  if (Serial.available() )
  {
  while (Serial.available() > 0)
  {
     //Serial.write(Serial.read());
     incomingChar = Serial.read();
     if (incomingChar == 'm')
     {
     Serial.println("Master Mode (Primary Transmiter Mode)");
     TransmitOrReciveMode =1;
     RFCtrl.HS = 555;
     }
     if (incomingChar == 's')
     {
     Serial.println("Slave Mode (Primary Reciver Mode)");
     TransmitOrReciveMode = 2;
     RFCtrl.HS = 555;
     }
     if (incomingChar == 'r')
     {
     Serial.println("Reciver Mode (Reciver Mode Only)");
     TransmitOrReciveMode = 3;
     }
     if (incomingChar == 'd') //Master Mode - Request (d)ata from Slave
     {
     Serial.println("Master Mode - Request data from Slave)");
     TransmitOrReciveMode = -1;
     RFCtrl.HS = 999;
     }
  }
  }
  //----------- Serial Mode Selection -----------
  
  
  Serial.print("HS Code: ");
  Serial.println(RFCtrl.HS);
  
  
  //--------- Master Mode - Primary Transm. mode --------
  if (TransmitOrReciveMode == 1 || TransmitOrReciveMode == -1)
  {
  
  if (RFCtrl.HS == 555 || !Mirf.dataReady())
  {
  Mirf.setRADDR((byte *)"serv1"); 
  Mirf.setTADDR((byte *)"clie1");
  
  RFCtrl.Speed = analogRead(1);
  RFCtrl.Position = analogRead(0);
  if(!Mirf.isSending())
  {Mirf.send((byte *)&RFCtrl);}
  
  if(Mirf.isSending())
  {
    tmrFaultTMO.start(1000);
    if (tmrFaultTMO.done())
    {
      tmrFaultTMO.stop();
      Serial.println("Fail sending");
      //break;
    }
  }
  else{tmrFaultTMO.stop();}
  }
  
  
  if (RFCtrl.HS == 999) //
  {
  //Serial.println("Pega ratao1");
  if(!Mirf.isSending() && Mirf.dataReady())
  {
  //Serial.println("Pega ratao 2");
  Mirf.getData((byte *) &RFCtrl);
  //Serial.print("Value Read: ");
  //Serial.println(RFCtrl.Speed);
  
  if (RFCtrl.HS == -999)
  {
    Serial.print("Recived data from Slave - Sucessuful");
  }
  else {Serial.print("Recived data from Slave - Fail");}
  TransmitOrReciveMode = 1;
  Serial.print("Finished 'Request Data Mode'");
  }
  }
  
  
  }
  //--------- Master Mode - Primary Transm. mode --------
  
  
  
  
  
  //--------- Slave Mode - Primary Reciv. mode ----------
  if (TransmitOrReciveMode == 2)
  {
  Mirf.setRADDR((byte *)"clie1");
  Mirf.setTADDR((byte *)"serv1");
  
  //Serial.print("HS Code: ");
  //Serial.println(RFCtrl.HS);
  //Serial.println("Pega ratao3");
  if(!Mirf.isSending() && Mirf.dataReady() && RFCtrl.HS == 555) //555 -> Listen Mode
  {
  //Serial.println("Pega ratao4");
  Mirf.getData((byte *) &RFCtrl);
  Serial.print("Speed Read: ");
  Serial.println(RFCtrl.Speed);
  //Serial.print("HS Read: ");
  //Serial.println(RFCtrl.HS);
  }
  //--- if the master requet data, so we must answer ---
  if (RFCtrl.HS == 999)
  {
  //Serial.println("Pega ratao5");
  if(!Mirf.isSending())
  {Mirf.send((byte *)&RFCtrl);}
  if(Mirf.isSending())
  {
  Serial.println("Trying Answer!");
  //Serial.println("Pega ratao6");
    tmrFaultTMO.start(1000);
    if (tmrFaultTMO.done())
    {
      tmrFaultTMO.stop();
      Serial.println("Fail sending");
      //break;
    }
  }
  else
  {
  tmrFaultTMO.stop();
  RFCtrl.HS = 555;
  Serial.println("Sucessuful sending");
  }
  
  }
  //--- if the master requet data, so we must answer ---
  }
  //--------- Slave Mode - Primary Reciv. mode ----------
  
  
  
  
  
  //---------------- Reciver mode Only ------------------
  if (TransmitOrReciveMode == 3)
  {
  Mirf.setRADDR((byte *)"clie1"); 
  //Mirf.setTADDR((byte *)"serv1");
  
  if(!Mirf.isSending() && Mirf.dataReady())
  {
  Mirf.getData((byte *) &RFCtrl);
  Serial.print("Value Read: ");
  Serial.println(RFCtrl.Speed);
  }
  
  }
  //---------------- Reciver mode Only ------------------
  
  wdt_reset();
} 
  
  
  
