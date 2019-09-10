/*
 --------  CONTROLE REMOTO  ------------
 
 Descrição:  coleta os valores analogicos do joystick e transmite para o carro
 */

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"


RF24 radio(9,10);// CE / CSN


void setup(void)
 {
  Serial.begin(57600);
  printf_begin();
  radio.begin();
  radio.setRetries(15,15); // delay end retries
  radio.setPayloadSize(8); // tamanho do pacote max 32 bytes
  radio.setChannel(0x40); 
  radio.openWritingPipe(0x111);
  radio.openReadingPipe(1,0x222);
  radio.openReadingPipe(3,0x123);
  radio.startListening();
  radio.printDetails();
  radio.stopListening();
  }

boolean Listening = 0; // 0 = stopListening    1 = startListening
int DataSend[4] = {0,0,0,0};
boolean SendOk=0;


void loop(void)//COM 18
{

  DataSend[0] = 5555;  // dado de controle (o carro só movimenta se o valor for 555 
  DataSend[1] = analogRead(A0);  // le valor analogico entrada A0 (movimento avança / recua)
  DataSend[2] = analogRead(A1);  // le valor analogico entrada A1 (movimento direita / esquetda)
  
    if (Send(DataSend,Listening)) // envia dados para o carro e verifica o evio, envio = 
   {
    Serial.print("Send   ");   //  se o envio for ok imprimme na serial o valores enviados
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
   Serial.println("Fail send ");  //  se o envio NÃO for ok imprimme na serial "Fail send "
   }
   
   delay(700);
}  
 
//-----------------------------  Função: Send  --------------------------------------------------------------//   
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


