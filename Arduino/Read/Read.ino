
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
  radio.openReadingPipe(3,0x111);
  delay(1000);
  //radio.startListening();
  radio.printDetails();
  Serial.println("Raaaa");
  //radio.stopListening();
  
}

int readArray[4] = {0,0,0,0};

void loop(void)//COM 21
{
  
  radio.startListening();
  
  //delay(1000);
  if (radio.available())
  {
  if (radio.read( &readArray, sizeof(int[4]) ) == 1)//radio.read( &readArray, sizeof(int[4]) );
  {
    radio.flush();
    Serial.println("Read OK. List Values Read: ");
    Serial.println(readArray[0], DEC);
    Serial.println(readArray[1], DEC);
    Serial.println(readArray[2], DEC);
    Serial.println(readArray[3], DEC);
    radio.stopListening();
  }
  else
  {
    Serial.println("Read Not OK. Value read: ");
  }
  //delay(1000);
  }
  //radio.stopListening();
  //delay(300);
}
