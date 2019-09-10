
#include <MathUtilities.h>
#include <Timer.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Servo.h>

RF24 radio(9,10); // CE / CSN
Servo myservo;
int recAvancaRecua;
int recDireitaEsquerda;


// the setup routine runs once when you press reset:
void setup() {                
 Serial.begin(57600);
  printf_begin();
  radio.begin();
  radio.setRetries(15,15);
  radio.setPayloadSize(8);
  radio.setChannel(0x40);
  radio.openWritingPipe(0x222);
  radio.openReadingPipe(1,0x111);
  radio.startListening();
  radio.printDetails();
  radio.stopListening();
  int outMotor = 2;
  pinMode(outMotor, OUTPUT); //Saida Motor tração
  int avanco = 3;
  pinMode(3, OUTPUT); // rele avanço
  int retorno = 4;
  pinMode(retorno, OUTPUT); // rele retorno
  myservo.attach(9);  // saida servomotor
  boolean Listening = 0; // 0 = stopListening    1 = startListening
  int DataRead[4] = {0,0,0,0};
  int angulo = 0;
}


void loop() {

if (DataRead[0]==5555)  //  se for 5555 o valor foi enviado pelo controle
 {
  sentido (DataRead[1],outMotor, avanco, retorno); // funçã de sentido passando referencia analogica (controle) e saidas: motor, avanco, recuo
  direcao(DataRead[2],angulo);  // chama função do servo e retorna o angulo por referencia
 }
else
 {
  chama função  
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



  
   
 
// <<--------- MONITOR SERIAL ------->>
  printDelay.start(500);
  if (printDelay.done())
  {
  Serial.println(sendHandshake);
  Serial.println(sendReturnHshk);
  Serial.println(sendSensorUS); 
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
  
void sentido (int _analogData, int _outMotor, int _avanco, int _retorno);{
 
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
  
  
