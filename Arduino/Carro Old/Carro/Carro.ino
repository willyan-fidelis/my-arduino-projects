
#include <MathUtilities.h>
#include <Timer.h>
#include <SPI.h>
#include <nRF24L01p.h>
#include <Servo.h>

nRF24L01p transciver(7,8);//CSN,CE
Servo myservo;
Timer tempo;
Timer msgDelay;
Timer printDelay;
Timer DelayfaultCom;
Timer DelayTranseiver;

int passo=0;
int angulo=0;

int sendHandshake;
int sendReturnHshk;
int sendSensorUS;
int recHandshake;
int recReturnHshk;
int recDirecao;
int recSentido;
int comFault = 9;
int comOk = 10;
int sensorSonic;
boolean ReadDone = 1;
int counter = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  delay(150);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  transciver.channel(90);
  transciver.TXaddress("CONTROLE");
  transciver.RXaddress("CARRO");
  transciver.init();
  Serial.begin(115200); 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  myservo.attach(9);
  pinMode(comFault, OUTPUT);
  pinMode(comOk, OUTPUT);
}


void loop() {

//DelayTranseiver.start(500);
  
//if (DelayTranseiver.done())
//{
  if (transciver.available())
    {
    transciver.read();
    transciver.rxPL(recHandshake);
    transciver.rxPL(recDirecao);
    transciver.rxPL(recSentido);
    ReadDone = 1;
  Serial.print(recHandshake);
  Serial.print("   ");
  Serial.print(recDirecao);
  Serial.print("   ");
  Serial.println(recSentido);
  if (transciver.read())
    {
    Serial.println("Lido");
    }  
  }
  delay(500);
//  if (ReadDone==1)
//    {
    sendHandshake = 4444; //random(1, 10000);
    transciver.txPL(sendHandshake);
    transciver.send(SLOW); 
    if (transciver.send())
    {
    Serial.println("Enviado");
    }
//    }
    
    
  //DelayTranseiver.stop();
//}
  
 //------- Chama função "StatusCom" status da comunicação ------>>   

  if (StatusCom (recReturnHshk, sendHandshake))
   {
   digitalWrite(comFault, HIGH);
   digitalWrite(comOk, LOW);  
   }
  else
   {
   digitalWrite(comFault, LOW);
   digitalWrite(comOk, HIGH);  
   }
 
//------- Indentifica o sentido e chama as funçoes "avança" e "recua" pasando o valor analogico ------>>   

  if (recSentido > 523) { avanca(recSentido, passo);  } // range para avanço 523~1023 
  if (recSentido < 500) { recua(recSentido, passo);  } // range para retorno 0~500
  if (recSentido >= 500) // range para parado 500~523
        {
        if (recSentido <= 523)
          { 
           digitalWrite(2, LOW);
           digitalWrite(3, LOW); 
           digitalWrite(4, LOW);
           digitalWrite(5, LOW); 
          }
        }  


//------- Chama a função "direcao" pasando o valor analogico ------>>   

  direcao(recDirecao,angulo);
   
 
// <<--------- MONITOR SERIAL ------->>
  printDelay.start(500);
  if (printDelay.done())
  {
    //Serial.println(sendHandshake);
  //Serial.println(sendReturnHshk);
  //Serial.println(sendSensorUS);  */
  printDelay.stop();
  }
}

//***********--------------------------  FUNÇÕES  -----------------------------*************

/*__________________________________________________________________________________________
                     Função para retornar o status da comunicação
  __________________________________________________________________________________________*/   

  boolean StatusCom (int _recReturnHshk,int _sendHandshake)
  {
  if (_recReturnHshk != _sendHandshake) 
     {
     DelayfaultCom.start(3000);
      if (DelayfaultCom.done() == 1)
       {
        return true;
       }
      }  
   else 
     {
     DelayfaultCom.stop();
     return false;
     }  
  }


/*__________________________________________________________________________________________
                        Função para girar motor de passo AVANÇA
  __________________________________________________________________________________________*/   
  
void avanca(int _value, int &_passo){

//--------------------------------------------------------------------->>>
// escala converte valor analogico (523~1023) para (30~3) milisegundos
//
_value = map(_value, 523, 1023, 40, 3);

// ref_vel = float((((anal-523)*(-0.074))+40) );
//  if (ref_vel > 40)
//  {
//  ref_vel = 40;
//  }
//  if (ref_vel < 3)
//  {
//  ref_vel = 3;
//  }
//
//----------------------------------------------------------------------<<<
  
  
//---------------------------------------------------------------------->>>
//   sequencia de passos para o motor
//
  switch (_passo)
  {
  case 0:  
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 1;
  tempo.stop();
 }
  break;
  
  case 1:
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 2;
  tempo.stop();
 }
  break;

  case 2:
  digitalWrite(2, LOW);
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 3;
  tempo.stop();
 }
  break;
  
  case 3:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 0;
  tempo.stop();
 }
  break; 
  }
}
//   fim da funçao 
//__________________________________________________________________________________________




/*__________________________________________________________________________________________
                        Função para girar motor de passo RECUA
  __________________________________________________________________________________________*/   
  
void recua(int _value, int &_passo){

//--------------------------------------------------------------------->>>
// escala converte valor analogico (523~1023) para (30~3) milisegundos
//

_value = map(_value, 0, 500, 3, 40);
 
//  ref_vel = float((((anal-500)*(0.074))+40) );
//  if (ref_vel > 40)
//  {
//  ref_vel = 40;
//  }
//  if (ref_vel < 3)
//  {
//  ref_vel = 3;
//  }
//
//----------------------------------------------------------------------<<<
  
  
//---------------------------------------------------------------------->>>
//   sequencia de passos para o motor
//
  
  switch (_passo)
  {
  case 0:  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 1;
  tempo.stop();
 }
  break;
  
  case 1:
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH); 
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 2;
  tempo.stop();
 }
  break;

  case 2:
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 3;
  tempo.stop();
 }
  break;
  
  case 3:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  tempo.start(long(_value));
  if (tempo.done() == 1)
 {
  _passo = 0;
  tempo.stop();
 }
  break; 
  }
}


/*__________________________________________________________________________________________
                        Função para girar motor de passo AVANÇA
  __________________________________________________________________________________________*/   
  
void direcao(float _value, int &_angulo)
{ 

  _value = map(_value, 0, 1023, 0, 180);
  myservo.write(_value);
  _angulo = _value; 
  
} 
  
  
