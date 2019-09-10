
#include <MathUtilities.h>
#include <Timer.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"


RF24 radio(9,10); //CE(PIN 9),CSN(PIN 10 on most arduino board or 53 on MEGA)

void setup(void)
{
  Serial.begin(57600);
  printf_begin();
  radio.begin();
  radio.setRetries(15,15); //Atrazo, Tentativas
  radio.setPayloadSize(8); //Tamanho do pacote em bytes.
  radio.setChannel(0x40);  //Canal de 0-127: xxx-yyy-yyy-yyy onde xxx é o numero do canal
  radio.openWritingPipe(0x111);
  radio.openReadingPipe(1,0x222);
  radio.startListening();
  radio.printDetails();
  //radio.stopListening();
  
}

int writeArray[4] = {5,0,0,10};

void loop(void)//COM 21
{
  radio.stopListening();
  if ( radio.write( &writeArray, sizeof(int[4]) ) == 1)
  {
    Serial.println(" Write OK");
  }
  else
  {
    //delay(1000);
    Serial.println("Write Not OK");
    
  }
  radio.startListening();
  
}
