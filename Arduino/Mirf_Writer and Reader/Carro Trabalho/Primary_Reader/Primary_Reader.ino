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
#include <Servo.h>

struct DataToComunicatio {
  int  Speed;
  int  Position;
  byte GoToLeftOrRight;
  byte GoToForwardOrBackward;
};

DataToComunicatio RFCtrl;
int Speed;
int Position;
int ActPosition;
int EndPosition;

Servo myservo;

const int EnAPin =6;
const int In1Pin = 5;
const int In2Pin = 2;


Timer tmrChangeLedStatus;
Timer tmrFaultTMO;
int ledPin = 4;
boolean ledPinValue = 0;
unsigned long ValueToBeWrite = 88;
unsigned long ValueToBeRead = 0;

void setup(){
  //wdt_enable(WDTO_2S); //Enable watchdog timer - 2 seconds
  Serial.begin(9600);
  //pinMode(ledPin, OUTPUT);
  
  Mirf.csnPin = 10;
  Mirf.cePin = 9; 
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init(); 
  Mirf.setRADDR((byte *)"serv1"); //Configure reciving address. 
  Mirf.setTADDR((byte *)"clie1");
  Mirf.payload = sizeof(RFCtrl);   
  Mirf.config(); 
  Serial.println("Setupping Reader... "); 
  
  pinMode(EnAPin, OUTPUT);
  pinMode(In1Pin, OUTPUT);
  pinMode(In2Pin, OUTPUT);
  
  myservo.attach(3); 
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
  
  //----------------- Read data -----------------
  tmrFaultTMO.start(200);
  if (tmrFaultTMO.done())
    {
      tmrFaultTMO.stop();
      Serial.println("Fail Reading");
      //Mirf.flushRx();
      Mirf.powerDown();
      Mirf.powerUpRx();
      //Mirf.powerUpTx();
      //Mirf.init();
      return;
    }
  
  RFCtrl.Position = 0;
  if(!Mirf.isSending() && Mirf.dataReady())
  {
  tmrFaultTMO.stop();
  Serial.println("Read sucessuful!");
  Mirf.getData((byte *) &RFCtrl);
  //Serial.print("Speed Read: ");
  //Serial.println(RFCtrl.Speed);
  //Serial.print("Position Read: ");
  //Serial.println(RFCtrl.Position);
  
  //----------------- Read data -----------------
  
  //----------------- Send data -----------------
  
  //ValueToBeWrite = 999;
  
  //Mirf.send((byte *)&RFCtrl);
  /*
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
  */
  //----------------- Send data -----------------
  //delay(1000);
  }
  
  // ---------- Aplication -----------------------------
  
  // Seed treats:
  
  //if (RFCtrl.Speed == -1)
  //{
  //  return;
  //}
  
  if (RFCtrl.Speed > 562) //Sentido 1 - Velocidade para frente.
  {
    Serial.print("+ Speed: ");
    Serial.println(RFCtrl.Speed);
    Speed = map(RFCtrl.Speed, 563, 1023, 0, 255); //map(value, fromLow, fromHigh, toLow, toHigh)
    digitalWrite(EnAPin, LOW);
    digitalWrite(In1Pin, HIGH);
    digitalWrite(In2Pin, LOW);
    analogWrite(EnAPin, Speed);
  }
  if (RFCtrl.Speed < 462) //Sentido 2 - Velocidade para tras - marcha ré.
  {
    Serial.print("- Speed: ");
    Serial.println(RFCtrl.Speed);
    Speed = map(RFCtrl.Speed, 461, 0, 0, 255); //map(value, fromLow, fromHigh, toLow, toHigh)
    digitalWrite(EnAPin, LOW);
    digitalWrite(In1Pin, LOW);
    digitalWrite(In2Pin, HIGH);
    analogWrite(EnAPin, Speed);
  }
  if ( (RFCtrl.Speed <= 562) && (RFCtrl.Speed >= 462) )  //Vecidade 0 - Parado
  {
    Serial.println("Stoped");
    digitalWrite(EnAPin, LOW);
    digitalWrite(In1Pin, LOW);
    digitalWrite(In2Pin, LOW);
    digitalWrite(EnAPin, HIGH);
  }
  
  //}
  //------------ Angle -------------
  
  //return;
  
  EndPosition = map(RFCtrl.Position, 0, 1023, 40, 95); 
  //myservo.write(Position); 
  
  Serial.print("Position Angle: ");
  Serial.println(Position);
  delay(15);
  
  //if ((EndPosition >= ActPosition + 2) || (EndPosition <= ActPosition - 2))
  //{
  //Serial.println("Spining..");
   
   for(Position = ActPosition; Position <= EndPosition; Position += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(Position);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(Position = ActPosition; Position>=EndPosition; Position-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(Position);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  ActPosition = EndPosition;
  
  //}
  //else
  //{myservo.write(Position);}
  //------------ Angle -------------
  
  
  // ---------- Aplication -----------------------------
} 
  
  
  
