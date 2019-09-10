#include <SPI.h>
#include <nRF24L01p.h>

nRF24L01p transmitter(7,8);//CSN,CE

void setup()
{
  delay(150);
  Serial.begin(115200);
  SPI.begin();
  //SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.setBitOrder(MSBFIRST);
  transmitter.channel(90);
  transmitter.RXaddress("Prado");
  transmitter.TXaddress("Artur");
  transmitter.init();
  //Serial.println("I'm PTX as transceiver");
}

int message;
int PRXsays;

void loop()
{
  /*
  delay(3000);
  
  if(Serial.available()>0)
  {
    message=0;
    message=Serial.read();
      transmitter.txPL(message);
      transmitter.send(SLOW);
      Serial.println("Dado enviado!");
      Serial.flush();
   }
   
  if(transmitter.available())
  {
    PRXsays=0;
    transmitter.read();
    transmitter.rxPL(PRXsays);
    Serial.print("Menssagen Lida: ");
    Serial.println(PRXsays);
  }
  */
  delay(100);
  int sensorValue;
  sensorValue = analogRead(A0); 
  transmitter.txPL(sensorValue);
  transmitter.send(SLOW);
  Serial.print("Dado lido e enviado: "); 
  Serial.println(sensorValue);
}

