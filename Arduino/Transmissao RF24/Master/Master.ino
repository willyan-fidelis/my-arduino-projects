/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/**
 * Example RF Radio Ping Pair
 *
 * This is an example of how to use the RF24 class.  Write this sketch to two different nodes,
 * connect the role_pin to ground on one.  The ping node sends the current time to the pong node,
 * which responds by sending the value back.  The ping node can then see how long the whole cycle
 * took.
 */
#include <MathUtilities.h>
#include <Timer.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"


RF24 radio(9,10);


void setup(void)
 {
  Serial.begin(57600);
  printf_begin();
  radio.begin();
  radio.setRetries(15,15);
  radio.setPayloadSize(8);
  radio.setChannel(0x40);
  radio.openWritingPipe(0x111);
  radio.openReadingPipe(1,0x222);
  radio.startListening();
  radio.printDetails();
  radio.stopListening();
  }

int StepSendCom = 0;
boolean Listening = 0; // 0 = stopListening    1 = startListening
int DataSend[4] = {101,202,303,404};
int DataRead[] = {0,0,0,0};
boolean SendOk=0;
boolean ReceiveOk=0;
Timer TimeOutCom;

void loop(void)//COM 18
{
 ReceiveOk=0;
 SendOk = Send(DataSend,Listening);
   if (SendOk)
   {
    Serial.print("Send   "); 
    Serial.print(DataSend[0]);
    Serial.print(" ");
    Serial.print(DataSend[1]);
    Serial.print(" ");
    Serial.print(DataSend[2]);
    Serial.print(" ");
    Serial.println(DataSend[3]);
    }
 else
   {
   Serial.println("Fail send ");
   }
   
   delay(700);
   
    SendOk = Send(DataSend,Listening);
   if (SendOk)
   {
    Serial.print("Send   "); 
    Serial.print(DataSend[0]);
    Serial.print(" ");
    Serial.print(DataSend[1]);
    Serial.print(" ");
    Serial.print(DataSend[2]);
    Serial.print(" ");
    Serial.print(DataSend[3]);
    }
 else
   {
   Serial.print("  Fail send  ");
   }
   
   delay(700);
   
    
    ReceiveOk = RequestData();
   if (ReceiveOk==1)
     {
      Serial.print("  Receive  "); 
      Serial.print(DataRead[0]);
      Serial.print(" ");
      Serial.print(DataRead[1]);
      Serial.print(" ");
      Serial.print(DataRead[2]);
      Serial.print(" ");
      Serial.print(DataRead[3]);
     }
 else 
     {
     Serial.print("  Read bad  ");
     }
    
Serial.println("   ");
}
//-------------------------------------------------------------------------------------------//   
boolean Send (int _DataSent[4], boolean &_Listening) 
{
   if (_Listening==1) 
     {
     radio.stopListening();
     _Listening = 0;
     }   
    boolean WriteOk = radio.write( &DataSend, sizeof(int[4]) );
    if (WriteOk==1)
     {
       radio.startListening();
       _Listening = 1;
       return 1;
     }
    else
     {
       radio.startListening();
       _Listening = 1;
       return 0;
     } 
  
       
} 


boolean Receive (int _DataRead[4], boolean &_listening)
{
  if (Listening==0) 
     {
     radio.startListening();
     Listening = 1;
     }   
    if ( radio.available() )
       {
       boolean ReadOk = radio.read( &DataRead, sizeof(int[4]) );
       if (ReadOk==1)
         {
         return 1;
         }
       else 
         { 
         return 0;
         }
     }
  else
   {
   return 0;
   } 
}
  
//-------------------------------------------------------------------------------------------------
boolean RequestData()
{
  StepSendCom = 0;
while(true){
//  Serial.println(StepSendCom);
 switch (StepSendCom) {  
   
  case 0:       // envia codigo para solicitar leitura ao escravo
    DataSend[0] = 9999;
    if (Send(DataSend,Listening))
       {StepSendCom = 1;} 
    else
       {StepSendCom = 3;}  // case Fault
  break;
    
  case 1:  //  abre a leitura e aguarda o recebimento
    if (Receive(DataRead,Listening))
       {
       StepSendCom = 2;
       }
    else
       {
        TimeOutCom.start(5000);
        if (TimeOutCom.done())
           {
           StepSendCom = 3;   // case Fault
           TimeOutCom.stop();
           }
        }
    break;
    
  case 2:
    DataSend[0] = 2222;
    return 1;
       
  case 3:    
    DataSend[0] = 2222;
    return 0;
 }
}
}
  
