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
  Mirf.setRADDR((byte *)"clie1"); //Configure reciving address. 
  Mirf.setTADDR((byte *)"serv1");
  Mirf.payload = sizeof(unsigned long);   
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
  
  
  
  
  //----------------- Send data -----------------
  ValueToBeWrite = 75;
  Serial.println("A");
  Mirf.send((byte *)&ValueToBeWrite);
  Serial.println("B");
  while(Mirf.isSending())
  {
    tmrFaultTMO.start(1000);
    if (tmrFaultTMO.done())
    {
      tmrFaultTMO.stop();
      Serial.println("Fail sending");
      break;
    }
  }
  Serial.println("Finished sending");
  //----------------- Send data -----------------
  /*
  while(Mirf.isSending()){
  }
  Serial.println("Finished sending");
  delay(10);
  while(!Mirf.dataReady()){
    //Serial.println("Waiting");
    if ( ( millis() - time ) > 1000 ) {
      Serial.println("Timeout on response from server!");
      return;
    }S
  }
  */
  /*
  Mirf.getData((byte *) &ValueToBeRead);
  Serial.print("Value Read: ");
  Serial.println(ValueToBeRead, DEC);
  
  delay(1000);
  */
  //delay(1000);
  
  //----------------- Read data -----------------
  //Serial.println("C");
  delay(10);
  if(!Mirf.isSending() && Mirf.dataReady())
  {
  Mirf.getData((byte *) &ValueToBeRead);
  Serial.print("Value Read: ");
  Serial.println(ValueToBeRead);
  }
  //----------------- Read data -----------------
  //delay(1000);
} 
  
  
  
