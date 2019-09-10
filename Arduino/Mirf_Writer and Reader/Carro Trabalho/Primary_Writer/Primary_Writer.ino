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
  int Speed;
  int Position;
  byte GoToLeftOrRight;
  byte GoToForwardOrBackward;
};

DataToComunicatio RFCtrl;


Timer tmrChangeLedStatus;
Timer tmrFaultTMO;
int ledPin = 4;
boolean ledPinValue = 0;
unsigned long ValueToBeWrite = 77;
unsigned long ValueToBeRead = 0;

void setup(){
  //wdt_enable(WDTO_2S); //Enable watchdog timer - 2 seconds
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  Mirf.csnPin = 10;
  Mirf.cePin = 9; 
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init(); 
  Mirf.setRADDR((byte *)"clie1"); //Configure reciving address. 
  Mirf.setTADDR((byte *)"serv1");
  Mirf.payload = sizeof(RFCtrl);   
  Mirf.config(); 
  Serial.println("Setupping Writing... "); 
  
  
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
  
  //----------------- Send data -----------------
  //ValueToBeWrite = 75;
  RFCtrl.Speed = analogRead(1);
  RFCtrl.Position = analogRead(0);
  
  Mirf.send((byte *)&RFCtrl);
  tmrFaultTMO.stop();
  while(Mirf.isSending())
  {
    tmrFaultTMO.start(100);
    if (tmrFaultTMO.done())
    {
      tmrFaultTMO.stop();
      Serial.println("Fail sending");
      break;
    }
  }
  //Serial.println("Finished sending");
  Serial.println(RFCtrl.Speed);
  Serial.println(RFCtrl.Position);
  //delay(10);
  //----------------- Send data -----------------
  
  //----------------- Read data -----------------
  /*while(!Mirf.dataReady())
  {
    tmrFaultTMO.start(200);
    if (tmrFaultTMO.done())
    {
      tmrFaultTMO.stop();
      Serial.println("Fail Reading");
      return;
    }
  }
  
  //if(!Mirf.isSending() && Mirf.dataReady())
  //{
  Mirf.getData((byte *) &RFCtrl);
  */
  
  
  //Serial.print("Value Read: ");
  //Serial.println(RFCtrl.Position);
  //}
  //----------------- Read data -----------------
  //delay(1000);
  
  // ---------- Aplication -----------------------------
  
  //Send the position to the primary reader ----------->
  //RFCtrl.Speed = map(analogRead(1), 0, 1023, 0, 100); //map(value, fromLow, fromHigh, toLow, toHigh)
  //Serial.print("Value Read: ");
  //Serial.println(analogRead(0), DEC);
  //Send the position to the primary reader <-----------
  
  // ---------- Aplication -----------------------------
} 
  
  
  
