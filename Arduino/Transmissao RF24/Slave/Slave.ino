
#include <MathUtilities.h>
#include <Timer.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"


RF24 radio(9,10); //CE,CSN

void setup(void)
{
  Serial.begin(57600);
  printf_begin();
  radio.begin();
  radio.setRetries(15,15); //Atrazo, Tentativas
  radio.setPayloadSize(8); //Tamanho do pacote em bytes.
  radio.setChannel(0x40);  //Canal de 0-127: xxx-yyy-yyy-yyy onde xxx é o numero do canal
  radio.openWritingPipe(0x222);
  radio.openReadingPipe(1,0x111);
  radio.startListening();
  radio.printDetails();
  Serial.println("Raaaa");
  radio.stopListening();
  
}

boolean Listening = 0; // 0 = stopListening    1 = startListening
int DataRead[4] = {0,0,0,0};
int DataSend[4] = {44,55,66,77};
boolean ReceiveOk=0;
boolean SendOk=0;
Timer TimeOutCom;
int StepSendCom = 0;

void loop(void)//COM 21
{
/*  
SendOk = Send(DataSend,Listening);
 delay(700);
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
   
   return; //----------------------------------------
  */
  
 ReceiveOk = Receive(DataRead,Listening);
 if (ReceiveOk == 1) 
         {
         Serial.print("Read Ok  "); 
         Serial.print(DataRead[0]);
         Serial.print(" ");
         Serial.print(DataRead[1]);
         Serial.print(" ");
         Serial.print(DataRead[2]);
         Serial.print(" ");
         Serial.println(DataRead[3]);
         }
       else 
         {
         //Serial.println("Read bad  ");
         //Serial.println(ReceiveOk), DEC;
         }
 
if (DataRead[0]==9999)
 {
   
   if (SendData())
   {
     Serial.println("SEND  ");
   }
   else
   {
     Serial.println("Send Fault  ");
   }
 }
//delay(100); 
  
}

//--------------------------------------------------------------------//

boolean Send (int _DataSend[4], boolean &_Listening) 
{
   if (_Listening==1) 
     {
     radio.stopListening();
     _Listening = 0;
     }   
    boolean WriteOk = radio.write( &_DataSend, sizeof(int[4]) );
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

//------------------------------------------------------------------------------------------------
boolean Receive (int _DataRead[4], boolean &_listening)
{
  if (Listening==0) 
     {
     radio.startListening();
     Listening = 1;
     }   
    if ( radio.available() )
       {
       boolean ReadOk = radio.read( &_DataRead, sizeof(int[4]) );
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

//-----------------------------------------------------------------------------
boolean SendData()
{
  boolean SendOk;
  StepSendCom = 0;
while(true){
 Serial.println(StepSendCom);
 switch (StepSendCom) {  
   
  case 0:       // envia dados
    DataSend[0] = 5555;
    
    Send(DataSend,Listening);
    SendOk = Send(DataSend,Listening);
    if (SendOk)    
       {StepSendCom = 1;} 
    else
       {StepSendCom = 2;}  // case Fault
  break;
  
  case 1:
  
    DataRead[0] = 0;
    DataSend[0] = 0;
    return 1;
    
  case 2: 
       TimeOutCom.start(5000);
        if (TimeOutCom.done())
           {
           TimeOutCom.stop();
           DataRead[0] = 0;
           DataSend[0] = 0;
           return 0;
           }
        StepSendCom = 0;
    break;
}
}
}
  
