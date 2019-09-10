#define F_CPU 16000000
#define ARDUINO 105
#include "Arduino.h"
#include "IR.h"
#include "RF.h"
#include "Timer.h"
#include "MathUtilities.h"
//
////Pin numbers:
//int btn1Pin = 6;
//int ledGreenPin = 3;
//int ledYellowPin = 4;
//int ledRedPin = 5;
//int IRLedEmiterPin = 13;
//int IRLedPin = 2;
////Tags:
//boolean btn1;
//boolean ledGreen;
//boolean ledYellow;
//boolean ledRed;
//boolean IRLed;
//boolean IRLedEmiter;
////
//boolean btn1ons;
////Other tags:
//int IRControlCase = 0;
//int SceneCtrl = 0;
////struct TScenes {int size; byte *take;};
////TScenes TVScene_SmartTV;
//
////------------------------- My Project Tags/includes -------------------------	
//TimeBsdCode myCode(38000);
//Timer AnySceneTime;
//Timer TVTimer;
//Timer VoiceRecog;
////------------------------- My Project Tags/includes -------------------------	
//
//void setup()
//{
	////------------------------- My Project Setup -------------------------
	//Serial.begin(9600);
	//pinMode(btn1Pin, INPUT);
	//pinMode(IRLedPin, INPUT);
	//
	//pinMode(ledGreenPin, OUTPUT);
	//pinMode(ledYellowPin, OUTPUT);
	//pinMode(ledRedPin, OUTPUT);
	//pinMode(IRLedEmiterPin, OUTPUT);
	//
	////Scenes:
	////Remote Ctrl options:
	////1 - Liga/Desliga
	////2 - Smart TV
	////3 - Navega p/ cima
	////4 - Navega p/ baixo
	////5 - Navega p/ direita
	////6 - Navega p esquerda
	////7 - Enter
	////8 - Volume +
	////9 - Volume -
	////10 - Liga/Desliga radio(home T.)
	//
	////
	////TVScene_SmartTV.size = 3;
	////TVScene_SmartTV.take = (byte*)::malloc(sizeof(byte)*TVScene_SmartTV.size);
	////TVScene_SmartTV.take[0] = 1; TVScene_SmartTV.take[0] = 2; TVScene_SmartTV.take[0] = 1;
	////------------------------- My Project Setup -------------------------
//}	
//
//void loop()
//{	
////------------------------- Input Mirror -------------------------	
	//btn1 = digitalRead(btn1Pin);
	//IRLed = digitalRead(IRLedPin);
////------------------------- Input Mirror -------------------------	
//
////------------------------- Main Program -------------------------	
//
//// Voice Control --->
//VoiceRecog.start(3000);
//if (VoiceRecog.done())
//{
	//VoiceRecog.stop();
	//Serial.println("ª!");
	////Serial.write(0x21);
//}
//// send data only when you receive data:
//if (Serial.available() > 0) {
	//// read the incoming byte:
	////incomingByte = Serial.read();
//
	//// say what you got:
	//Serial.print("I received: ");
	//Serial.println(Serial.read(), DEC);
//}
//// Voice Control <---
//
//myCode.m_code.stTeached = 1;
////Remote Ctrl options:
////1 - Liga/Desliga
////2 - Smart TV
////3 - Navega p/ cima
////4 - Navega p/ baixo
////5 - Navega p/ direita
////6 - Navega p esquerda
////7 - Enter
////8 - Volume +
////9 - Volume -
////10 - Liga/Desliga radio(home T.)
//
////Net Flix Secene:
//if (btn1 & !btn1ons)
//{
	//SceneCtrl = 1;	
//}
//btn1ons = btn1;
//switch (SceneCtrl)
//{
	//case 1:
	////Taken 1 - Turn TV on:
	//if (IRControlCase == 0)
	//{
		//IRControlCase = 1;
		//SceneCtrl = 2;
	//}
	//break;
	//case 2:
	////Taken 2 - Turn Smart TV on:
	//if (IRControlCase == 0)
	//{
		//IRControlCase = 2;
		//SceneCtrl = 3;
	//}
	//break;
	//case 3:
	////Taken 3 - Go to rigth:
	//if (IRControlCase == 0)
	//{
		//IRControlCase = 5;
		//SceneCtrl = 4;
	//}
	//break;
	//case 4:
	////Taken 4 - Go to rigth:
	//if (IRControlCase == 0)
	//{
		//IRControlCase = 5;
		//SceneCtrl = 5;
	//}
	//break;
	//case 5:
	////Taken 5 - Press Enter:
	//if (IRControlCase == 0)
	//{
		//IRControlCase = 7;
		//SceneCtrl = 6;
	//}
	//break;
	//case 6:
	////Taken 6 - Press Enter:
	//if (IRControlCase == 0)
	//{
		//TVTimer.start(20000);
		//if (TVTimer.done())
		//{
			//TVTimer.stop();
			//
			//IRControlCase = 7;
			//SceneCtrl = 0;
		//}
	//}
	//break;
//}
//
//if (SceneCtrl != 0)
//{
	//AnySceneTime.start(300);
	//if (AnySceneTime.done())
	//{
		//AnySceneTime.stop();
		//ledRed = !ledRed;
	//}
//} 
//else
//{
	//ledRed = 0;
//}
//
////IR Control Options:
//switch (IRControlCase)
//{
	//case 1:
	////Liga/Desliga:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4080;
	//myCode.m_code.pulses[0].lowValue = 4200;
	//myCode.m_code.pulses[1].highValue = 510;
	//myCode.m_code.pulses[1].lowValue = 1560;
	//myCode.m_code.pulses[2].highValue = 480;
	//myCode.m_code.pulses[2].lowValue = 1590;
	//myCode.m_code.pulses[3].highValue = 480;
	//myCode.m_code.pulses[3].lowValue = 1590;
	//myCode.m_code.pulses[4].highValue = 480;
	//myCode.m_code.pulses[4].lowValue = 540;
	//myCode.m_code.pulses[5].highValue = 480;
	//myCode.m_code.pulses[5].lowValue = 540;
	//myCode.m_code.pulses[6].highValue = 480;
	//myCode.m_code.pulses[6].lowValue = 540;
	//myCode.m_code.pulses[7].highValue = 480;
	//myCode.m_code.pulses[7].lowValue = 540;
	//myCode.m_code.pulses[8].highValue = 480;
	//myCode.m_code.pulses[8].lowValue = 540;
	//myCode.m_code.pulses[9].highValue = 480;
	//myCode.m_code.pulses[9].lowValue = 1560;
	//myCode.m_code.pulses[10].highValue = 480;
	//myCode.m_code.pulses[10].lowValue = 1590;
	//myCode.m_code.pulses[11].highValue = 480;
	//myCode.m_code.pulses[11].lowValue = 1590;
	//myCode.m_code.pulses[12].highValue = 480;
	//myCode.m_code.pulses[12].lowValue = 540;
	//myCode.m_code.pulses[13].highValue = 480;
	//myCode.m_code.pulses[13].lowValue = 540;
	//myCode.m_code.pulses[14].highValue = 480;
	//myCode.m_code.pulses[14].lowValue = 540;
	//myCode.m_code.pulses[15].highValue = 480;
	//myCode.m_code.pulses[15].lowValue = 540;
	//myCode.m_code.pulses[16].highValue = 480;
	//myCode.m_code.pulses[16].lowValue = 540;
	//myCode.m_code.pulses[17].highValue = 480;
	//myCode.m_code.pulses[17].lowValue = 540;
	//myCode.m_code.pulses[18].highValue = 450;
	//myCode.m_code.pulses[18].lowValue = 1590;
	//myCode.m_code.pulses[19].highValue = 480;
	//myCode.m_code.pulses[19].lowValue = 540;
	//myCode.m_code.pulses[20].highValue = 480;
	//myCode.m_code.pulses[20].lowValue = 540;
	//myCode.m_code.pulses[21].highValue = 480;
	//myCode.m_code.pulses[21].lowValue = 540;
	//myCode.m_code.pulses[22].highValue = 480;
	//myCode.m_code.pulses[22].lowValue = 540;
	//myCode.m_code.pulses[23].highValue = 480;
	//myCode.m_code.pulses[23].lowValue = 540;
	//myCode.m_code.pulses[24].highValue = 480;
	//myCode.m_code.pulses[24].lowValue = 540;
	//myCode.m_code.pulses[25].highValue = 480;
	//myCode.m_code.pulses[25].lowValue = 1590;
	//myCode.m_code.pulses[26].highValue = 480;
	//myCode.m_code.pulses[26].lowValue = 540;
	//myCode.m_code.pulses[27].highValue = 480;
	//myCode.m_code.pulses[27].lowValue = 1590;
	//myCode.m_code.pulses[28].highValue = 450;
	//myCode.m_code.pulses[28].lowValue = 1590;
	//myCode.m_code.pulses[29].highValue = 480;
	//myCode.m_code.pulses[29].lowValue = 1590;
	//myCode.m_code.pulses[30].highValue = 480;
	//myCode.m_code.pulses[30].lowValue = 1590;
	//myCode.m_code.pulses[31].highValue = 480;
	//myCode.m_code.pulses[31].lowValue = 1590;
	//myCode.m_code.pulses[32].highValue = 450;
	//myCode.m_code.pulses[32].lowValue = 1590;
	//myCode.m_code.pulses[33].highValue = 480;
	//myCode.m_code.pulses[33].lowValue = 43710;
	//myCode.m_code.pulses[34].highValue = 4110;
	//myCode.m_code.pulses[34].lowValue = 4200;
	//myCode.m_code.pulses[35].highValue = 480;
	//myCode.m_code.pulses[35].lowValue = 1590;
	//myCode.m_code.pulses[36].highValue = 480;
	//myCode.m_code.pulses[36].lowValue = 1590;
	//myCode.m_code.pulses[37].highValue = 480;
	//myCode.m_code.pulses[37].lowValue = 1560;
	//myCode.m_code.pulses[38].highValue = 510;
	//myCode.m_code.pulses[38].lowValue = 510;
	//myCode.m_code.pulses[39].highValue = 480;
	//myCode.m_code.pulses[39].lowValue = 540;
	//myCode.m_code.pulses[40].highValue = 480;
	//myCode.m_code.pulses[40].lowValue = 540;
	//myCode.m_code.pulses[41].highValue = 480;
	//myCode.m_code.pulses[41].lowValue = 540;
	//myCode.m_code.pulses[42].highValue = 480;
	//myCode.m_code.pulses[42].lowValue = 540;
	//myCode.m_code.pulses[43].highValue = 480;
	//myCode.m_code.pulses[43].lowValue = 1590;
	//myCode.m_code.pulses[44].highValue = 480;
	//myCode.m_code.pulses[44].lowValue = 1590;
	//myCode.m_code.pulses[45].highValue = 480;
	//myCode.m_code.pulses[45].lowValue = 1560;
	//myCode.m_code.pulses[46].highValue = 510;
	//myCode.m_code.pulses[46].lowValue = 510;
	//myCode.m_code.pulses[47].highValue = 480;
	//myCode.m_code.pulses[47].lowValue = 540;
	//myCode.m_code.pulses[48].highValue = 480;
	//myCode.m_code.pulses[48].lowValue = 540;
	//myCode.m_code.pulses[49].highValue = 480;
	//myCode.m_code.pulses[49].lowValue = 540;
	//myCode.m_code.pulses[50].highValue = 480;
	//myCode.m_code.pulses[50].lowValue = 540;
	//myCode.m_code.pulses[51].highValue = 480;
	//myCode.m_code.pulses[51].lowValue = 540;
	//myCode.m_code.pulses[52].highValue = 480;
	//myCode.m_code.pulses[52].lowValue = 1590;
	//myCode.m_code.pulses[53].highValue = 480;
	//myCode.m_code.pulses[53].lowValue = 540;
	//myCode.m_code.pulses[54].highValue = 480;
	//myCode.m_code.pulses[54].lowValue = 540;
	//myCode.m_code.pulses[55].highValue = 480;
	//myCode.m_code.pulses[55].lowValue = 540;
	//myCode.m_code.pulses[56].highValue = 480;
	//myCode.m_code.pulses[56].lowValue = 540;
	//myCode.m_code.pulses[57].highValue = 450;
	//myCode.m_code.pulses[57].lowValue = 570;
	//myCode.m_code.pulses[58].highValue = 450;
	//myCode.m_code.pulses[58].lowValue = 570;
	//myCode.m_code.pulses[59].highValue = 450;
	//myCode.m_code.pulses[59].lowValue = 1590;
	//myCode.m_code.pulses[60].highValue = 480;
	//myCode.m_code.pulses[60].lowValue = 540;
	//myCode.m_code.pulses[61].highValue = 480;
	//myCode.m_code.pulses[61].lowValue = 1590;
	//myCode.m_code.pulses[62].highValue = 480;
	//myCode.m_code.pulses[62].lowValue = 1590;
	//myCode.m_code.pulses[63].highValue = 480;
	//myCode.m_code.pulses[63].lowValue = 1590;
	//myCode.m_code.pulses[64].highValue = 450;
	//myCode.m_code.pulses[64].lowValue = 1590;
	//myCode.m_code.pulses[65].highValue = 480;
	//myCode.m_code.pulses[65].lowValue = 1590;
	//myCode.m_code.pulses[66].highValue = 480;
	//myCode.m_code.pulses[66].lowValue = 1590;
	//myCode.m_code.pulses[67].highValue = 480;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 10000;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 2:
	////Smart TV:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4140;
	//myCode.m_code.pulses[0].lowValue = 4170;
	//myCode.m_code.pulses[1].highValue = 540;
	//myCode.m_code.pulses[1].lowValue = 1500;
	//myCode.m_code.pulses[2].highValue = 540;
	//myCode.m_code.pulses[2].lowValue = 1530;
	//myCode.m_code.pulses[3].highValue = 540;
	//myCode.m_code.pulses[3].lowValue = 1530;
	//myCode.m_code.pulses[4].highValue = 540;
	//myCode.m_code.pulses[4].lowValue = 480;
	//myCode.m_code.pulses[5].highValue = 540;
	//myCode.m_code.pulses[5].lowValue = 480;
	//myCode.m_code.pulses[6].highValue = 540;
	//myCode.m_code.pulses[6].lowValue = 480;
	//myCode.m_code.pulses[7].highValue = 540;
	//myCode.m_code.pulses[7].lowValue = 480;
	//myCode.m_code.pulses[8].highValue = 540;
	//myCode.m_code.pulses[8].lowValue = 480;
	//myCode.m_code.pulses[9].highValue = 510;
	//myCode.m_code.pulses[9].lowValue = 1530;
	//myCode.m_code.pulses[10].highValue = 540;
	//myCode.m_code.pulses[10].lowValue = 1530;
	//myCode.m_code.pulses[11].highValue = 540;
	//myCode.m_code.pulses[11].lowValue = 1530;
	//myCode.m_code.pulses[12].highValue = 540;
	//myCode.m_code.pulses[12].lowValue = 480;
	//myCode.m_code.pulses[13].highValue = 540;
	//myCode.m_code.pulses[13].lowValue = 480;
	//myCode.m_code.pulses[14].highValue = 540;
	//myCode.m_code.pulses[14].lowValue = 450;
	//myCode.m_code.pulses[15].highValue = 570;
	//myCode.m_code.pulses[15].lowValue = 450;
	//myCode.m_code.pulses[16].highValue = 540;
	//myCode.m_code.pulses[16].lowValue = 480;
	//myCode.m_code.pulses[17].highValue = 540;
	//myCode.m_code.pulses[17].lowValue = 1530;
	//myCode.m_code.pulses[18].highValue = 540;
	//myCode.m_code.pulses[18].lowValue = 480;
	//myCode.m_code.pulses[19].highValue = 540;
	//myCode.m_code.pulses[19].lowValue = 480;
	//myCode.m_code.pulses[20].highValue = 540;
	//myCode.m_code.pulses[20].lowValue = 1500;
	//myCode.m_code.pulses[21].highValue = 570;
	//myCode.m_code.pulses[21].lowValue = 1500;
	//myCode.m_code.pulses[22].highValue = 540;
	//myCode.m_code.pulses[22].lowValue = 1530;
	//myCode.m_code.pulses[23].highValue = 540;
	//myCode.m_code.pulses[23].lowValue = 1530;
	//myCode.m_code.pulses[24].highValue = 540;
	//myCode.m_code.pulses[24].lowValue = 480;
	//myCode.m_code.pulses[25].highValue = 540;
	//myCode.m_code.pulses[25].lowValue = 480;
	//myCode.m_code.pulses[26].highValue = 510;
	//myCode.m_code.pulses[26].lowValue = 1530;
	//myCode.m_code.pulses[27].highValue = 540;
	//myCode.m_code.pulses[27].lowValue = 1530;
	//myCode.m_code.pulses[28].highValue = 540;
	//myCode.m_code.pulses[28].lowValue = 480;
	//myCode.m_code.pulses[29].highValue = 540;
	//myCode.m_code.pulses[29].lowValue = 480;
	//myCode.m_code.pulses[30].highValue = 540;
	//myCode.m_code.pulses[30].lowValue = 480;
	//myCode.m_code.pulses[31].highValue = 540;
	//myCode.m_code.pulses[31].lowValue = 480;
	//myCode.m_code.pulses[32].highValue = 510;
	//myCode.m_code.pulses[32].lowValue = 1530;
	//myCode.m_code.pulses[33].highValue = 540;
	//myCode.m_code.pulses[33].lowValue = 43650;
	//myCode.m_code.pulses[34].highValue = 4170;
	//myCode.m_code.pulses[34].lowValue = 4140;
	//myCode.m_code.pulses[35].highValue = 540;
	//myCode.m_code.pulses[35].lowValue = 1530;
	//myCode.m_code.pulses[36].highValue = 540;
	//myCode.m_code.pulses[36].lowValue = 1530;
	//myCode.m_code.pulses[37].highValue = 540;
	//myCode.m_code.pulses[37].lowValue = 1500;
	//myCode.m_code.pulses[38].highValue = 540;
	//myCode.m_code.pulses[38].lowValue = 480;
	//myCode.m_code.pulses[39].highValue = 540;
	//myCode.m_code.pulses[39].lowValue = 480;
	//myCode.m_code.pulses[40].highValue = 540;
	//myCode.m_code.pulses[40].lowValue = 480;
	//myCode.m_code.pulses[41].highValue = 540;
	//myCode.m_code.pulses[41].lowValue = 480;
	//myCode.m_code.pulses[42].highValue = 540;
	//myCode.m_code.pulses[42].lowValue = 480;
	//myCode.m_code.pulses[43].highValue = 540;
	//myCode.m_code.pulses[43].lowValue = 1500;
	//myCode.m_code.pulses[44].highValue = 570;
	//myCode.m_code.pulses[44].lowValue = 1500;
	//myCode.m_code.pulses[45].highValue = 540;
	//myCode.m_code.pulses[45].lowValue = 1530;
	//myCode.m_code.pulses[46].highValue = 540;
	//myCode.m_code.pulses[46].lowValue = 480;
	//myCode.m_code.pulses[47].highValue = 540;
	//myCode.m_code.pulses[47].lowValue = 480;
	//myCode.m_code.pulses[48].highValue = 540;
	//myCode.m_code.pulses[48].lowValue = 480;
	//myCode.m_code.pulses[49].highValue = 540;
	//myCode.m_code.pulses[49].lowValue = 450;
	//myCode.m_code.pulses[50].highValue = 540;
	//myCode.m_code.pulses[50].lowValue = 480;
	//myCode.m_code.pulses[51].highValue = 540;
	//myCode.m_code.pulses[51].lowValue = 1530;
	//myCode.m_code.pulses[52].highValue = 540;
	//myCode.m_code.pulses[52].lowValue = 480;
	//myCode.m_code.pulses[53].highValue = 540;
	//myCode.m_code.pulses[53].lowValue = 480;
	//myCode.m_code.pulses[54].highValue = 540;
	//myCode.m_code.pulses[54].lowValue = 1500;
	//myCode.m_code.pulses[55].highValue = 540;
	//myCode.m_code.pulses[55].lowValue = 1530;
	//myCode.m_code.pulses[56].highValue = 540;
	//myCode.m_code.pulses[56].lowValue = 1530;
	//myCode.m_code.pulses[57].highValue = 540;
	//myCode.m_code.pulses[57].lowValue = 1530;
	//myCode.m_code.pulses[58].highValue = 540;
	//myCode.m_code.pulses[58].lowValue = 450;
	//myCode.m_code.pulses[59].highValue = 570;
	//myCode.m_code.pulses[59].lowValue = 450;
	//myCode.m_code.pulses[60].highValue = 540;
	//myCode.m_code.pulses[60].lowValue = 1530;
	//myCode.m_code.pulses[61].highValue = 540;
	//myCode.m_code.pulses[61].lowValue = 1530;
	//myCode.m_code.pulses[62].highValue = 540;
	//myCode.m_code.pulses[62].lowValue = 480;
	//myCode.m_code.pulses[63].highValue = 540;
	//myCode.m_code.pulses[63].lowValue = 480;
	//myCode.m_code.pulses[64].highValue = 540;
	//myCode.m_code.pulses[64].lowValue = 480;
	//myCode.m_code.pulses[65].highValue = 540;
	//myCode.m_code.pulses[65].lowValue = 450;
	//myCode.m_code.pulses[66].highValue = 540;
	//myCode.m_code.pulses[66].lowValue = 1530;
	//myCode.m_code.pulses[67].highValue = 540;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 9000;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 3:
	////Navega p/ cima:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4140;
	//myCode.m_code.pulses[0].lowValue = 4170;
	//myCode.m_code.pulses[1].highValue = 540;
	//myCode.m_code.pulses[1].lowValue = 1530;
	//myCode.m_code.pulses[2].highValue = 510;
	//myCode.m_code.pulses[2].lowValue = 1560;
	//myCode.m_code.pulses[3].highValue = 510;
	//myCode.m_code.pulses[3].lowValue = 1530;
	//myCode.m_code.pulses[4].highValue = 540;
	//myCode.m_code.pulses[4].lowValue = 480;
	//myCode.m_code.pulses[5].highValue = 540;
	//myCode.m_code.pulses[5].lowValue = 480;
	//myCode.m_code.pulses[6].highValue = 540;
	//myCode.m_code.pulses[6].lowValue = 480;
	//myCode.m_code.pulses[7].highValue = 540;
	//myCode.m_code.pulses[7].lowValue = 480;
	//myCode.m_code.pulses[8].highValue = 510;
	//myCode.m_code.pulses[8].lowValue = 510;
	//myCode.m_code.pulses[9].highValue = 510;
	//myCode.m_code.pulses[9].lowValue = 1560;
	//myCode.m_code.pulses[10].highValue = 510;
	//myCode.m_code.pulses[10].lowValue = 1560;
	//myCode.m_code.pulses[11].highValue = 510;
	//myCode.m_code.pulses[11].lowValue = 1530;
	//myCode.m_code.pulses[12].highValue = 540;
	//myCode.m_code.pulses[12].lowValue = 480;
	//myCode.m_code.pulses[13].highValue = 540;
	//myCode.m_code.pulses[13].lowValue = 480;
	//myCode.m_code.pulses[14].highValue = 540;
	//myCode.m_code.pulses[14].lowValue = 480;
	//myCode.m_code.pulses[15].highValue = 510;
	//myCode.m_code.pulses[15].lowValue = 510;
	//myCode.m_code.pulses[16].highValue = 510;
	//myCode.m_code.pulses[16].lowValue = 510;
	//myCode.m_code.pulses[17].highValue = 510;
	//myCode.m_code.pulses[17].lowValue = 510;
	//myCode.m_code.pulses[18].highValue = 510;
	//myCode.m_code.pulses[18].lowValue = 510;
	//myCode.m_code.pulses[19].highValue = 510;
	//myCode.m_code.pulses[19].lowValue = 510;
	//myCode.m_code.pulses[20].highValue = 510;
	//myCode.m_code.pulses[20].lowValue = 480;
	//myCode.m_code.pulses[21].highValue = 540;
	//myCode.m_code.pulses[21].lowValue = 480;
	//myCode.m_code.pulses[22].highValue = 540;
	//myCode.m_code.pulses[22].lowValue = 1530;
	//myCode.m_code.pulses[23].highValue = 540;
	//myCode.m_code.pulses[23].lowValue = 1530;
	//myCode.m_code.pulses[24].highValue = 510;
	//myCode.m_code.pulses[24].lowValue = 510;
	//myCode.m_code.pulses[25].highValue = 510;
	//myCode.m_code.pulses[25].lowValue = 1530;
	//myCode.m_code.pulses[26].highValue = 540;
	//myCode.m_code.pulses[26].lowValue = 1530;
	//myCode.m_code.pulses[27].highValue = 540;
	//myCode.m_code.pulses[27].lowValue = 1530;
	//myCode.m_code.pulses[28].highValue = 510;
	//myCode.m_code.pulses[28].lowValue = 1530;
	//myCode.m_code.pulses[29].highValue = 540;
	//myCode.m_code.pulses[29].lowValue = 1530;
	//myCode.m_code.pulses[30].highValue = 540;
	//myCode.m_code.pulses[30].lowValue = 480;
	//myCode.m_code.pulses[31].highValue = 540;
	//myCode.m_code.pulses[31].lowValue = 480;
	//myCode.m_code.pulses[32].highValue = 540;
	//myCode.m_code.pulses[32].lowValue = 1530;
	//myCode.m_code.pulses[33].highValue = 510;
	//myCode.m_code.pulses[33].lowValue = 43650;
	//myCode.m_code.pulses[34].highValue = 4140;
	//myCode.m_code.pulses[34].lowValue = 4170;
	//myCode.m_code.pulses[35].highValue = 480;
	//myCode.m_code.pulses[35].lowValue = 1590;
	//myCode.m_code.pulses[36].highValue = 480;
	//myCode.m_code.pulses[36].lowValue = 1590;
	//myCode.m_code.pulses[37].highValue = 480;
	//myCode.m_code.pulses[37].lowValue = 1590;
	//myCode.m_code.pulses[38].highValue = 450;
	//myCode.m_code.pulses[38].lowValue = 540;
	//myCode.m_code.pulses[39].highValue = 480;
	//myCode.m_code.pulses[39].lowValue = 540;
	//myCode.m_code.pulses[40].highValue = 480;
	//myCode.m_code.pulses[40].lowValue = 540;
	//myCode.m_code.pulses[41].highValue = 480;
	//myCode.m_code.pulses[41].lowValue = 540;
	//myCode.m_code.pulses[42].highValue = 480;
	//myCode.m_code.pulses[42].lowValue = 540;
	//myCode.m_code.pulses[43].highValue = 480;
	//myCode.m_code.pulses[43].lowValue = 1590;
	//myCode.m_code.pulses[44].highValue = 480;
	//myCode.m_code.pulses[44].lowValue = 1590;
	//myCode.m_code.pulses[45].highValue = 480;
	//myCode.m_code.pulses[45].lowValue = 1560;
	//myCode.m_code.pulses[46].highValue = 480;
	//myCode.m_code.pulses[46].lowValue = 540;
	//myCode.m_code.pulses[47].highValue = 480;
	//myCode.m_code.pulses[47].lowValue = 540;
	//myCode.m_code.pulses[48].highValue = 480;
	//myCode.m_code.pulses[48].lowValue = 540;
	//myCode.m_code.pulses[49].highValue = 480;
	//myCode.m_code.pulses[49].lowValue = 540;
	//myCode.m_code.pulses[50].highValue = 480;
	//myCode.m_code.pulses[50].lowValue = 540;
	//myCode.m_code.pulses[51].highValue = 480;
	//myCode.m_code.pulses[51].lowValue = 540;
	//myCode.m_code.pulses[52].highValue = 480;
	//myCode.m_code.pulses[52].lowValue = 540;
	//myCode.m_code.pulses[53].highValue = 480;
	//myCode.m_code.pulses[53].lowValue = 540;
	//myCode.m_code.pulses[54].highValue = 480;
	//myCode.m_code.pulses[54].lowValue = 540;
	//myCode.m_code.pulses[55].highValue = 480;
	//myCode.m_code.pulses[55].lowValue = 540;
	//myCode.m_code.pulses[56].highValue = 480;
	//myCode.m_code.pulses[56].lowValue = 1560;
	//myCode.m_code.pulses[57].highValue = 480;
	//myCode.m_code.pulses[57].lowValue = 1590;
	//myCode.m_code.pulses[58].highValue = 480;
	//myCode.m_code.pulses[58].lowValue = 540;
	//myCode.m_code.pulses[59].highValue = 480;
	//myCode.m_code.pulses[59].lowValue = 1590;
	//myCode.m_code.pulses[60].highValue = 480;
	//myCode.m_code.pulses[60].lowValue = 1590;
	//myCode.m_code.pulses[61].highValue = 480;
	//myCode.m_code.pulses[61].lowValue = 1560;
	//myCode.m_code.pulses[62].highValue = 480;
	//myCode.m_code.pulses[62].lowValue = 1590;
	//myCode.m_code.pulses[63].highValue = 480;
	//myCode.m_code.pulses[63].lowValue = 1590;
	//myCode.m_code.pulses[64].highValue = 480;
	//myCode.m_code.pulses[64].lowValue = 540;
	//myCode.m_code.pulses[65].highValue = 480;
	//myCode.m_code.pulses[65].lowValue = 540;
	//myCode.m_code.pulses[66].highValue = 480;
	//myCode.m_code.pulses[66].lowValue = 1560;
	//myCode.m_code.pulses[67].highValue = 480;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 4:
	////Navega p/ baixo:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4140;
	//myCode.m_code.pulses[0].lowValue = 4170;
	//myCode.m_code.pulses[1].highValue = 480;
	//myCode.m_code.pulses[1].lowValue = 1590;
	//myCode.m_code.pulses[2].highValue = 480;
	//myCode.m_code.pulses[2].lowValue = 1590;
	//myCode.m_code.pulses[3].highValue = 450;
	//myCode.m_code.pulses[3].lowValue = 1590;
	//myCode.m_code.pulses[4].highValue = 480;
	//myCode.m_code.pulses[4].lowValue = 540;
	//myCode.m_code.pulses[5].highValue = 540;
	//myCode.m_code.pulses[5].lowValue = 480;
	//myCode.m_code.pulses[6].highValue = 510;
	//myCode.m_code.pulses[6].lowValue = 510;
	//myCode.m_code.pulses[7].highValue = 480;
	//myCode.m_code.pulses[7].lowValue = 540;
	//myCode.m_code.pulses[8].highValue = 480;
	//myCode.m_code.pulses[8].lowValue = 540;
	//myCode.m_code.pulses[9].highValue = 480;
	//myCode.m_code.pulses[9].lowValue = 1590;
	//myCode.m_code.pulses[10].highValue = 480;
	//myCode.m_code.pulses[10].lowValue = 1590;
	//myCode.m_code.pulses[11].highValue = 480;
	//myCode.m_code.pulses[11].lowValue = 1560;
	//myCode.m_code.pulses[12].highValue = 480;
	//myCode.m_code.pulses[12].lowValue = 540;
	//myCode.m_code.pulses[13].highValue = 480;
	//myCode.m_code.pulses[13].lowValue = 540;
	//myCode.m_code.pulses[14].highValue = 480;
	//myCode.m_code.pulses[14].lowValue = 540;
	//myCode.m_code.pulses[15].highValue = 480;
	//myCode.m_code.pulses[15].lowValue = 540;
	//myCode.m_code.pulses[16].highValue = 480;
	//myCode.m_code.pulses[16].lowValue = 540;
	//myCode.m_code.pulses[17].highValue = 480;
	//myCode.m_code.pulses[17].lowValue = 1590;
	//myCode.m_code.pulses[18].highValue = 480;
	//myCode.m_code.pulses[18].lowValue = 540;
	//myCode.m_code.pulses[19].highValue = 480;
	//myCode.m_code.pulses[19].lowValue = 540;
	//myCode.m_code.pulses[20].highValue = 480;
	//myCode.m_code.pulses[20].lowValue = 540;
	//myCode.m_code.pulses[21].highValue = 480;
	//myCode.m_code.pulses[21].lowValue = 540;
	//myCode.m_code.pulses[22].highValue = 480;
	//myCode.m_code.pulses[22].lowValue = 1560;
	//myCode.m_code.pulses[23].highValue = 480;
	//myCode.m_code.pulses[23].lowValue = 1590;
	//myCode.m_code.pulses[24].highValue = 480;
	//myCode.m_code.pulses[24].lowValue = 540;
	//myCode.m_code.pulses[25].highValue = 480;
	//myCode.m_code.pulses[25].lowValue = 540;
	//myCode.m_code.pulses[26].highValue = 480;
	//myCode.m_code.pulses[26].lowValue = 1590;
	//myCode.m_code.pulses[27].highValue = 480;
	//myCode.m_code.pulses[27].lowValue = 1590;
	//myCode.m_code.pulses[28].highValue = 480;
	//myCode.m_code.pulses[28].lowValue = 1560;
	//myCode.m_code.pulses[29].highValue = 510;
	//myCode.m_code.pulses[29].lowValue = 1560;
	//myCode.m_code.pulses[30].highValue = 480;
	//myCode.m_code.pulses[30].lowValue = 540;
	//myCode.m_code.pulses[31].highValue = 480;
	//myCode.m_code.pulses[31].lowValue = 540;
	//myCode.m_code.pulses[32].highValue = 480;
	//myCode.m_code.pulses[32].lowValue = 1590;
	//myCode.m_code.pulses[33].highValue = 480;
	//myCode.m_code.pulses[33].lowValue = 43710;
	//myCode.m_code.pulses[34].highValue = 4080;
	//myCode.m_code.pulses[34].lowValue = 4230;
	//myCode.m_code.pulses[35].highValue = 480;
	//myCode.m_code.pulses[35].lowValue = 1560;
	//myCode.m_code.pulses[36].highValue = 480;
	//myCode.m_code.pulses[36].lowValue = 1590;
	//myCode.m_code.pulses[37].highValue = 480;
	//myCode.m_code.pulses[37].lowValue = 1590;
	//myCode.m_code.pulses[38].highValue = 480;
	//myCode.m_code.pulses[38].lowValue = 540;
	//myCode.m_code.pulses[39].highValue = 480;
	//myCode.m_code.pulses[39].lowValue = 540;
	//myCode.m_code.pulses[40].highValue = 480;
	//myCode.m_code.pulses[40].lowValue = 540;
	//myCode.m_code.pulses[41].highValue = 480;
	//myCode.m_code.pulses[41].lowValue = 540;
	//myCode.m_code.pulses[42].highValue = 480;
	//myCode.m_code.pulses[42].lowValue = 540;
	//myCode.m_code.pulses[43].highValue = 480;
	//myCode.m_code.pulses[43].lowValue = 1560;
	//myCode.m_code.pulses[44].highValue = 480;
	//myCode.m_code.pulses[44].lowValue = 1590;
	//myCode.m_code.pulses[45].highValue = 480;
	//myCode.m_code.pulses[45].lowValue = 1590;
	//myCode.m_code.pulses[46].highValue = 480;
	//myCode.m_code.pulses[46].lowValue = 540;
	//myCode.m_code.pulses[47].highValue = 480;
	//myCode.m_code.pulses[47].lowValue = 540;
	//myCode.m_code.pulses[48].highValue = 480;
	//myCode.m_code.pulses[48].lowValue = 540;
	//myCode.m_code.pulses[49].highValue = 480;
	//myCode.m_code.pulses[49].lowValue = 540;
	//myCode.m_code.pulses[50].highValue = 480;
	//myCode.m_code.pulses[50].lowValue = 540;
	//myCode.m_code.pulses[51].highValue = 480;
	//myCode.m_code.pulses[51].lowValue = 1560;
	//myCode.m_code.pulses[52].highValue = 480;
	//myCode.m_code.pulses[52].lowValue = 540;
	//myCode.m_code.pulses[53].highValue = 480;
	//myCode.m_code.pulses[53].lowValue = 540;
	//myCode.m_code.pulses[54].highValue = 480;
	//myCode.m_code.pulses[54].lowValue = 540;
	//myCode.m_code.pulses[55].highValue = 480;
	//myCode.m_code.pulses[55].lowValue = 540;
	//myCode.m_code.pulses[56].highValue = 480;
	//myCode.m_code.pulses[56].lowValue = 1590;
	//myCode.m_code.pulses[57].highValue = 480;
	//myCode.m_code.pulses[57].lowValue = 1590;
	//myCode.m_code.pulses[58].highValue = 480;
	//myCode.m_code.pulses[58].lowValue = 540;
	//myCode.m_code.pulses[59].highValue = 480;
	//myCode.m_code.pulses[59].lowValue = 540;
	//myCode.m_code.pulses[60].highValue = 480;
	//myCode.m_code.pulses[60].lowValue = 1560;
	//myCode.m_code.pulses[61].highValue = 480;
	//myCode.m_code.pulses[61].lowValue = 1590;
	//myCode.m_code.pulses[62].highValue = 480;
	//myCode.m_code.pulses[62].lowValue = 1590;
	//myCode.m_code.pulses[63].highValue = 480;
	//myCode.m_code.pulses[63].lowValue = 1590;
	//myCode.m_code.pulses[64].highValue = 480;
	//myCode.m_code.pulses[64].lowValue = 540;
	//myCode.m_code.pulses[65].highValue = 480;
	//myCode.m_code.pulses[65].lowValue = 540;
	//myCode.m_code.pulses[66].highValue = 480;
	//myCode.m_code.pulses[66].lowValue = 1560;
	//myCode.m_code.pulses[67].highValue = 480;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 5:
	////Navega p/ direita:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4080;
	//myCode.m_code.pulses[0].lowValue = 4200;
	//myCode.m_code.pulses[1].highValue = 480;
	//myCode.m_code.pulses[1].lowValue = 1590;
	//myCode.m_code.pulses[2].highValue = 480;
	//myCode.m_code.pulses[2].lowValue = 1590;
	//myCode.m_code.pulses[3].highValue = 480;
	//myCode.m_code.pulses[3].lowValue = 1590;
	//myCode.m_code.pulses[4].highValue = 480;
	//myCode.m_code.pulses[4].lowValue = 540;
	//myCode.m_code.pulses[5].highValue = 480;
	//myCode.m_code.pulses[5].lowValue = 540;
	//myCode.m_code.pulses[6].highValue = 480;
	//myCode.m_code.pulses[6].lowValue = 540;
	//myCode.m_code.pulses[7].highValue = 450;
	//myCode.m_code.pulses[7].lowValue = 570;
	//myCode.m_code.pulses[8].highValue = 450;
	//myCode.m_code.pulses[8].lowValue = 570;
	//myCode.m_code.pulses[9].highValue = 450;
	//myCode.m_code.pulses[9].lowValue = 1590;
	//myCode.m_code.pulses[10].highValue = 480;
	//myCode.m_code.pulses[10].lowValue = 1590;
	//myCode.m_code.pulses[11].highValue = 480;
	//myCode.m_code.pulses[11].lowValue = 1590;
	//myCode.m_code.pulses[12].highValue = 480;
	//myCode.m_code.pulses[12].lowValue = 540;
	//myCode.m_code.pulses[13].highValue = 480;
	//myCode.m_code.pulses[13].lowValue = 540;
	//myCode.m_code.pulses[14].highValue = 480;
	//myCode.m_code.pulses[14].lowValue = 540;
	//myCode.m_code.pulses[15].highValue = 480;
	//myCode.m_code.pulses[15].lowValue = 540;
	//myCode.m_code.pulses[16].highValue = 480;
	//myCode.m_code.pulses[16].lowValue = 540;
	//myCode.m_code.pulses[17].highValue = 480;
	//myCode.m_code.pulses[17].lowValue = 540;
	//myCode.m_code.pulses[18].highValue = 480;
	//myCode.m_code.pulses[18].lowValue = 1560;
	//myCode.m_code.pulses[19].highValue = 480;
	//myCode.m_code.pulses[19].lowValue = 540;
	//myCode.m_code.pulses[20].highValue = 480;
	//myCode.m_code.pulses[20].lowValue = 540;
	//myCode.m_code.pulses[21].highValue = 480;
	//myCode.m_code.pulses[21].lowValue = 540;
	//myCode.m_code.pulses[22].highValue = 480;
	//myCode.m_code.pulses[22].lowValue = 1590;
	//myCode.m_code.pulses[23].highValue = 480;
	//myCode.m_code.pulses[23].lowValue = 1590;
	//myCode.m_code.pulses[24].highValue = 480;
	//myCode.m_code.pulses[24].lowValue = 540;
	//myCode.m_code.pulses[25].highValue = 480;
	//myCode.m_code.pulses[25].lowValue = 1560;
	//myCode.m_code.pulses[26].highValue = 480;
	//myCode.m_code.pulses[26].lowValue = 540;
	//myCode.m_code.pulses[27].highValue = 480;
	//myCode.m_code.pulses[27].lowValue = 1590;
	//myCode.m_code.pulses[28].highValue = 480;
	//myCode.m_code.pulses[28].lowValue = 1590;
	//myCode.m_code.pulses[29].highValue = 480;
	//myCode.m_code.pulses[29].lowValue = 1590;
	//myCode.m_code.pulses[30].highValue = 480;
	//myCode.m_code.pulses[30].lowValue = 540;
	//myCode.m_code.pulses[31].highValue = 480;
	//myCode.m_code.pulses[31].lowValue = 540;
	//myCode.m_code.pulses[32].highValue = 480;
	//myCode.m_code.pulses[32].lowValue = 1560;
	//myCode.m_code.pulses[33].highValue = 480;
	//myCode.m_code.pulses[33].lowValue = 43710;
	//myCode.m_code.pulses[34].highValue = 4140;
	//myCode.m_code.pulses[34].lowValue = 4170;
	//myCode.m_code.pulses[35].highValue = 480;
	//myCode.m_code.pulses[35].lowValue = 1590;
	//myCode.m_code.pulses[36].highValue = 480;
	//myCode.m_code.pulses[36].lowValue = 1590;
	//myCode.m_code.pulses[37].highValue = 480;
	//myCode.m_code.pulses[37].lowValue = 1590;
	//myCode.m_code.pulses[38].highValue = 450;
	//myCode.m_code.pulses[38].lowValue = 570;
	//myCode.m_code.pulses[39].highValue = 450;
	//myCode.m_code.pulses[39].lowValue = 570;
	//myCode.m_code.pulses[40].highValue = 450;
	//myCode.m_code.pulses[40].lowValue = 570;
	//myCode.m_code.pulses[41].highValue = 450;
	//myCode.m_code.pulses[41].lowValue = 540;
	//myCode.m_code.pulses[42].highValue = 480;
	//myCode.m_code.pulses[42].lowValue = 540;
	//myCode.m_code.pulses[43].highValue = 480;
	//myCode.m_code.pulses[43].lowValue = 1590;
	//myCode.m_code.pulses[44].highValue = 480;
	//myCode.m_code.pulses[44].lowValue = 1590;
	//myCode.m_code.pulses[45].highValue = 480;
	//myCode.m_code.pulses[45].lowValue = 1590;
	//myCode.m_code.pulses[46].highValue = 480;
	//myCode.m_code.pulses[46].lowValue = 540;
	//myCode.m_code.pulses[47].highValue = 480;
	//myCode.m_code.pulses[47].lowValue = 540;
	//myCode.m_code.pulses[48].highValue = 480;
	//myCode.m_code.pulses[48].lowValue = 510;
	//myCode.m_code.pulses[49].highValue = 480;
	//myCode.m_code.pulses[49].lowValue = 540;
	//myCode.m_code.pulses[50].highValue = 480;
	//myCode.m_code.pulses[50].lowValue = 540;
	//myCode.m_code.pulses[51].highValue = 480;
	//myCode.m_code.pulses[51].lowValue = 540;
	//myCode.m_code.pulses[52].highValue = 480;
	//myCode.m_code.pulses[52].lowValue = 1590;
	//myCode.m_code.pulses[53].highValue = 480;
	//myCode.m_code.pulses[53].lowValue = 540;
	//myCode.m_code.pulses[54].highValue = 480;
	//myCode.m_code.pulses[54].lowValue = 540;
	//myCode.m_code.pulses[55].highValue = 480;
	//myCode.m_code.pulses[55].lowValue = 540;
	//myCode.m_code.pulses[56].highValue = 480;
	//myCode.m_code.pulses[56].lowValue = 1590;
	//myCode.m_code.pulses[57].highValue = 480;
	//myCode.m_code.pulses[57].lowValue = 1560;
	//myCode.m_code.pulses[58].highValue = 510;
	//myCode.m_code.pulses[58].lowValue = 510;
	//myCode.m_code.pulses[59].highValue = 480;
	//myCode.m_code.pulses[59].lowValue = 1590;
	//myCode.m_code.pulses[60].highValue = 480;
	//myCode.m_code.pulses[60].lowValue = 540;
	//myCode.m_code.pulses[61].highValue = 480;
	//myCode.m_code.pulses[61].lowValue = 1590;
	//myCode.m_code.pulses[62].highValue = 480;
	//myCode.m_code.pulses[62].lowValue = 1590;
	//myCode.m_code.pulses[63].highValue = 480;
	//myCode.m_code.pulses[63].lowValue = 1560;
	//myCode.m_code.pulses[64].highValue = 510;
	//myCode.m_code.pulses[64].lowValue = 510;
	//myCode.m_code.pulses[65].highValue = 480;
	//myCode.m_code.pulses[65].lowValue = 540;
	//myCode.m_code.pulses[66].highValue = 480;
	//myCode.m_code.pulses[66].lowValue = 1590;
	//myCode.m_code.pulses[67].highValue = 480;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 6:
	////Navega p esquerda:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4110;
	//myCode.m_code.pulses[0].lowValue = 4200;
	//myCode.m_code.pulses[1].highValue = 480;
	//myCode.m_code.pulses[1].lowValue = 1590;
	//myCode.m_code.pulses[2].highValue = 480;
	//myCode.m_code.pulses[2].lowValue = 1590;
	//myCode.m_code.pulses[3].highValue = 480;
	//myCode.m_code.pulses[3].lowValue = 1560;
	//myCode.m_code.pulses[4].highValue = 480;
	//myCode.m_code.pulses[4].lowValue = 540;
	//myCode.m_code.pulses[5].highValue = 480;
	//myCode.m_code.pulses[5].lowValue = 540;
	//myCode.m_code.pulses[6].highValue = 480;
	//myCode.m_code.pulses[6].lowValue = 540;
	//myCode.m_code.pulses[7].highValue = 480;
	//myCode.m_code.pulses[7].lowValue = 540;
	//myCode.m_code.pulses[8].highValue = 480;
	//myCode.m_code.pulses[8].lowValue = 540;
	//myCode.m_code.pulses[9].highValue = 480;
	//myCode.m_code.pulses[9].lowValue = 1590;
	//myCode.m_code.pulses[10].highValue = 480;
	//myCode.m_code.pulses[10].lowValue = 1560;
	//myCode.m_code.pulses[11].highValue = 510;
	//myCode.m_code.pulses[11].lowValue = 1560;
	//myCode.m_code.pulses[12].highValue = 480;
	//myCode.m_code.pulses[12].lowValue = 540;
	//myCode.m_code.pulses[13].highValue = 480;
	//myCode.m_code.pulses[13].lowValue = 540;
	//myCode.m_code.pulses[14].highValue = 480;
	//myCode.m_code.pulses[14].lowValue = 540;
	//myCode.m_code.pulses[15].highValue = 480;
	//myCode.m_code.pulses[15].lowValue = 540;
	//myCode.m_code.pulses[16].highValue = 480;
	//myCode.m_code.pulses[16].lowValue = 540;
	//myCode.m_code.pulses[17].highValue = 480;
	//myCode.m_code.pulses[17].lowValue = 1590;
	//myCode.m_code.pulses[18].highValue = 480;
	//myCode.m_code.pulses[18].lowValue = 540;
	//myCode.m_code.pulses[19].highValue = 480;
	//myCode.m_code.pulses[19].lowValue = 1560;
	//myCode.m_code.pulses[20].highValue = 480;
	//myCode.m_code.pulses[20].lowValue = 540;
	//myCode.m_code.pulses[21].highValue = 480;
	//myCode.m_code.pulses[21].lowValue = 540;
	//myCode.m_code.pulses[22].highValue = 480;
	//myCode.m_code.pulses[22].lowValue = 1590;
	//myCode.m_code.pulses[23].highValue = 480;
	//myCode.m_code.pulses[23].lowValue = 1590;
	//myCode.m_code.pulses[24].highValue = 480;
	//myCode.m_code.pulses[24].lowValue = 540;
	//myCode.m_code.pulses[25].highValue = 480;
	//myCode.m_code.pulses[25].lowValue = 540;
	//myCode.m_code.pulses[26].highValue = 480;
	//myCode.m_code.pulses[26].lowValue = 1560;
	//myCode.m_code.pulses[27].highValue = 480;
	//myCode.m_code.pulses[27].lowValue = 540;
	//myCode.m_code.pulses[28].highValue = 480;
	//myCode.m_code.pulses[28].lowValue = 1590;
	//myCode.m_code.pulses[29].highValue = 480;
	//myCode.m_code.pulses[29].lowValue = 1590;
	//myCode.m_code.pulses[30].highValue = 480;
	//myCode.m_code.pulses[30].lowValue = 540;
	//myCode.m_code.pulses[31].highValue = 480;
	//myCode.m_code.pulses[31].lowValue = 540;
	//myCode.m_code.pulses[32].highValue = 480;
	//myCode.m_code.pulses[32].lowValue = 1560;
	//myCode.m_code.pulses[33].highValue = 510;
	//myCode.m_code.pulses[33].lowValue = 43680;
	//myCode.m_code.pulses[34].highValue = 4110;
	//myCode.m_code.pulses[34].lowValue = 4200;
	//myCode.m_code.pulses[35].highValue = 480;
	//myCode.m_code.pulses[35].lowValue = 1590;
	//myCode.m_code.pulses[36].highValue = 480;
	//myCode.m_code.pulses[36].lowValue = 1590;
	//myCode.m_code.pulses[37].highValue = 480;
	//myCode.m_code.pulses[37].lowValue = 1590;
	//myCode.m_code.pulses[38].highValue = 450;
	//myCode.m_code.pulses[38].lowValue = 540;
	//myCode.m_code.pulses[39].highValue = 480;
	//myCode.m_code.pulses[39].lowValue = 540;
	//myCode.m_code.pulses[40].highValue = 480;
	//myCode.m_code.pulses[40].lowValue = 540;
	//myCode.m_code.pulses[41].highValue = 480;
	//myCode.m_code.pulses[41].lowValue = 540;
	//myCode.m_code.pulses[42].highValue = 480;
	//myCode.m_code.pulses[42].lowValue = 540;
	//myCode.m_code.pulses[43].highValue = 480;
	//myCode.m_code.pulses[43].lowValue = 1590;
	//myCode.m_code.pulses[44].highValue = 510;
	//myCode.m_code.pulses[44].lowValue = 1560;
	//myCode.m_code.pulses[45].highValue = 510;
	//myCode.m_code.pulses[45].lowValue = 1530;
	//myCode.m_code.pulses[46].highValue = 510;
	//myCode.m_code.pulses[46].lowValue = 510;
	//myCode.m_code.pulses[47].highValue = 510;
	//myCode.m_code.pulses[47].lowValue = 510;
	//myCode.m_code.pulses[48].highValue = 480;
	//myCode.m_code.pulses[48].lowValue = 540;
	//myCode.m_code.pulses[49].highValue = 480;
	//myCode.m_code.pulses[49].lowValue = 540;
	//myCode.m_code.pulses[50].highValue = 510;
	//myCode.m_code.pulses[50].lowValue = 510;
	//myCode.m_code.pulses[51].highValue = 510;
	//myCode.m_code.pulses[51].lowValue = 1560;
	//myCode.m_code.pulses[52].highValue = 510;
	//myCode.m_code.pulses[52].lowValue = 510;
	//myCode.m_code.pulses[53].highValue = 510;
	//myCode.m_code.pulses[53].lowValue = 1560;
	//myCode.m_code.pulses[54].highValue = 480;
	//myCode.m_code.pulses[54].lowValue = 510;
	//myCode.m_code.pulses[55].highValue = 510;
	//myCode.m_code.pulses[55].lowValue = 510;
	//myCode.m_code.pulses[56].highValue = 510;
	//myCode.m_code.pulses[56].lowValue = 1560;
	//myCode.m_code.pulses[57].highValue = 540;
	//myCode.m_code.pulses[57].lowValue = 1530;
	//myCode.m_code.pulses[58].highValue = 540;
	//myCode.m_code.pulses[58].lowValue = 480;
	//myCode.m_code.pulses[59].highValue = 510;
	//myCode.m_code.pulses[59].lowValue = 510;
	//myCode.m_code.pulses[60].highValue = 510;
	//myCode.m_code.pulses[60].lowValue = 1530;
	//myCode.m_code.pulses[61].highValue = 540;
	//myCode.m_code.pulses[61].lowValue = 480;
	//myCode.m_code.pulses[62].highValue = 540;
	//myCode.m_code.pulses[62].lowValue = 1530;
	//myCode.m_code.pulses[63].highValue = 540;
	//myCode.m_code.pulses[63].lowValue = 1530;
	//myCode.m_code.pulses[64].highValue = 540;
	//myCode.m_code.pulses[64].lowValue = 480;
	//myCode.m_code.pulses[65].highValue = 510;
	//myCode.m_code.pulses[65].lowValue = 510;
	//myCode.m_code.pulses[66].highValue = 510;
	//myCode.m_code.pulses[66].lowValue = 1530;
	//myCode.m_code.pulses[67].highValue = 540;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 7:
	////Enter:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4110;
	//myCode.m_code.pulses[0].lowValue = 4200;
	//myCode.m_code.pulses[1].highValue = 510;
	//myCode.m_code.pulses[1].lowValue = 1560;
	//myCode.m_code.pulses[2].highValue = 510;
	//myCode.m_code.pulses[2].lowValue = 1560;
	//myCode.m_code.pulses[3].highValue = 510;
	//myCode.m_code.pulses[3].lowValue = 1530;
	//myCode.m_code.pulses[4].highValue = 510;
	//myCode.m_code.pulses[4].lowValue = 510;
	//myCode.m_code.pulses[5].highValue = 510;
	//myCode.m_code.pulses[5].lowValue = 510;
	//myCode.m_code.pulses[6].highValue = 510;
	//myCode.m_code.pulses[6].lowValue = 510;
	//myCode.m_code.pulses[7].highValue = 480;
	//myCode.m_code.pulses[7].lowValue = 540;
	//myCode.m_code.pulses[8].highValue = 510;
	//myCode.m_code.pulses[8].lowValue = 510;
	//myCode.m_code.pulses[9].highValue = 480;
	//myCode.m_code.pulses[9].lowValue = 1590;
	//myCode.m_code.pulses[10].highValue = 510;
	//myCode.m_code.pulses[10].lowValue = 1560;
	//myCode.m_code.pulses[11].highValue = 480;
	//myCode.m_code.pulses[11].lowValue = 1560;
	//myCode.m_code.pulses[12].highValue = 510;
	//myCode.m_code.pulses[12].lowValue = 510;
	//myCode.m_code.pulses[13].highValue = 510;
	//myCode.m_code.pulses[13].lowValue = 510;
	//myCode.m_code.pulses[14].highValue = 480;
	//myCode.m_code.pulses[14].lowValue = 540;
	//myCode.m_code.pulses[15].highValue = 480;
	//myCode.m_code.pulses[15].lowValue = 540;
	//myCode.m_code.pulses[16].highValue = 480;
	//myCode.m_code.pulses[16].lowValue = 540;
	//myCode.m_code.pulses[17].highValue = 480;
	//myCode.m_code.pulses[17].lowValue = 540;
	//myCode.m_code.pulses[18].highValue = 510;
	//myCode.m_code.pulses[18].lowValue = 510;
	//myCode.m_code.pulses[19].highValue = 510;
	//myCode.m_code.pulses[19].lowValue = 510;
	//myCode.m_code.pulses[20].highValue = 480;
	//myCode.m_code.pulses[20].lowValue = 1590;
	//myCode.m_code.pulses[21].highValue = 480;
	//myCode.m_code.pulses[21].lowValue = 510;
	//myCode.m_code.pulses[22].highValue = 510;
	//myCode.m_code.pulses[22].lowValue = 1560;
	//myCode.m_code.pulses[23].highValue = 510;
	//myCode.m_code.pulses[23].lowValue = 1560;
	//myCode.m_code.pulses[24].highValue = 510;
	//myCode.m_code.pulses[24].lowValue = 510;
	//myCode.m_code.pulses[25].highValue = 480;
	//myCode.m_code.pulses[25].lowValue = 1590;
	//myCode.m_code.pulses[26].highValue = 480;
	//myCode.m_code.pulses[26].lowValue = 1560;
	//myCode.m_code.pulses[27].highValue = 510;
	//myCode.m_code.pulses[27].lowValue = 1560;
	//myCode.m_code.pulses[28].highValue = 510;
	//myCode.m_code.pulses[28].lowValue = 510;
	//myCode.m_code.pulses[29].highValue = 480;
	//myCode.m_code.pulses[29].lowValue = 1590;
	//myCode.m_code.pulses[30].highValue = 510;
	//myCode.m_code.pulses[30].lowValue = 510;
	//myCode.m_code.pulses[31].highValue = 510;
	//myCode.m_code.pulses[31].lowValue = 510;
	//myCode.m_code.pulses[32].highValue = 480;
	//myCode.m_code.pulses[32].lowValue = 1560;
	//myCode.m_code.pulses[33].highValue = 510;
	//myCode.m_code.pulses[33].lowValue = 43680;
	//myCode.m_code.pulses[34].highValue = 4080;
	//myCode.m_code.pulses[34].lowValue = 4230;
	//myCode.m_code.pulses[35].highValue = 510;
	//myCode.m_code.pulses[35].lowValue = 1560;
	//myCode.m_code.pulses[36].highValue = 510;
	//myCode.m_code.pulses[36].lowValue = 1530;
	//myCode.m_code.pulses[37].highValue = 510;
	//myCode.m_code.pulses[37].lowValue = 1560;
	//myCode.m_code.pulses[38].highValue = 510;
	//myCode.m_code.pulses[38].lowValue = 510;
	//myCode.m_code.pulses[39].highValue = 480;
	//myCode.m_code.pulses[39].lowValue = 540;
	//myCode.m_code.pulses[40].highValue = 480;
	//myCode.m_code.pulses[40].lowValue = 540;
	//myCode.m_code.pulses[41].highValue = 480;
	//myCode.m_code.pulses[41].lowValue = 540;
	//myCode.m_code.pulses[42].highValue = 510;
	//myCode.m_code.pulses[42].lowValue = 510;
	//myCode.m_code.pulses[43].highValue = 480;
	//myCode.m_code.pulses[43].lowValue = 1590;
	//myCode.m_code.pulses[44].highValue = 510;
	//myCode.m_code.pulses[44].lowValue = 1530;
	//myCode.m_code.pulses[45].highValue = 510;
	//myCode.m_code.pulses[45].lowValue = 1560;
	//myCode.m_code.pulses[46].highValue = 510;
	//myCode.m_code.pulses[46].lowValue = 510;
	//myCode.m_code.pulses[47].highValue = 480;
	//myCode.m_code.pulses[47].lowValue = 540;
	//myCode.m_code.pulses[48].highValue = 480;
	//myCode.m_code.pulses[48].lowValue = 540;
	//myCode.m_code.pulses[49].highValue = 480;
	//myCode.m_code.pulses[49].lowValue = 540;
	//myCode.m_code.pulses[50].highValue = 480;
	//myCode.m_code.pulses[50].lowValue = 540;
	//myCode.m_code.pulses[51].highValue = 510;
	//myCode.m_code.pulses[51].lowValue = 510;
	//myCode.m_code.pulses[52].highValue = 480;
	//myCode.m_code.pulses[52].lowValue = 540;
	//myCode.m_code.pulses[53].highValue = 480;
	//myCode.m_code.pulses[53].lowValue = 540;
	//myCode.m_code.pulses[54].highValue = 480;
	//myCode.m_code.pulses[54].lowValue = 1560;
	//myCode.m_code.pulses[55].highValue = 510;
	//myCode.m_code.pulses[55].lowValue = 510;
	//myCode.m_code.pulses[56].highValue = 510;
	//myCode.m_code.pulses[56].lowValue = 1560;
	//myCode.m_code.pulses[57].highValue = 510;
	//myCode.m_code.pulses[57].lowValue = 1560;
	//myCode.m_code.pulses[58].highValue = 510;
	//myCode.m_code.pulses[58].lowValue = 510;
	//myCode.m_code.pulses[59].highValue = 480;
	//myCode.m_code.pulses[59].lowValue = 1560;
	//myCode.m_code.pulses[60].highValue = 510;
	//myCode.m_code.pulses[60].lowValue = 1560;
	//myCode.m_code.pulses[61].highValue = 510;
	//myCode.m_code.pulses[61].lowValue = 1560;
	//myCode.m_code.pulses[62].highValue = 510;
	//myCode.m_code.pulses[62].lowValue = 510;
	//myCode.m_code.pulses[63].highValue = 510;
	//myCode.m_code.pulses[63].lowValue = 1560;
	//myCode.m_code.pulses[64].highValue = 480;
	//myCode.m_code.pulses[64].lowValue = 540;
	//myCode.m_code.pulses[65].highValue = 480;
	//myCode.m_code.pulses[65].lowValue = 540;
	//myCode.m_code.pulses[66].highValue = 480;
	//myCode.m_code.pulses[66].lowValue = 1560;
	//myCode.m_code.pulses[67].highValue = 510;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 8:
	////Volume +:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4170;
	//myCode.m_code.pulses[0].lowValue = 4140;
	//myCode.m_code.pulses[1].highValue = 540;
	//myCode.m_code.pulses[1].lowValue = 1530;
	//myCode.m_code.pulses[2].highValue = 540;
	//myCode.m_code.pulses[2].lowValue = 1530;
	//myCode.m_code.pulses[3].highValue = 540;
	//myCode.m_code.pulses[3].lowValue = 1500;
	//myCode.m_code.pulses[4].highValue = 540;
	//myCode.m_code.pulses[4].lowValue = 480;
	//myCode.m_code.pulses[5].highValue = 540;
	//myCode.m_code.pulses[5].lowValue = 480;
	//myCode.m_code.pulses[6].highValue = 540;
	//myCode.m_code.pulses[6].lowValue = 480;
	//myCode.m_code.pulses[7].highValue = 540;
	//myCode.m_code.pulses[7].lowValue = 480;
	//myCode.m_code.pulses[8].highValue = 540;
	//myCode.m_code.pulses[8].lowValue = 480;
	//myCode.m_code.pulses[9].highValue = 540;
	//myCode.m_code.pulses[9].lowValue = 1500;
	//myCode.m_code.pulses[10].highValue = 540;
	//myCode.m_code.pulses[10].lowValue = 1530;
	//myCode.m_code.pulses[11].highValue = 540;
	//myCode.m_code.pulses[11].lowValue = 1530;
	//myCode.m_code.pulses[12].highValue = 540;
	//myCode.m_code.pulses[12].lowValue = 480;
	//myCode.m_code.pulses[13].highValue = 540;
	//myCode.m_code.pulses[13].lowValue = 480;
	//myCode.m_code.pulses[14].highValue = 540;
	//myCode.m_code.pulses[14].lowValue = 450;
	//myCode.m_code.pulses[15].highValue = 570;
	//myCode.m_code.pulses[15].lowValue = 450;
	//myCode.m_code.pulses[16].highValue = 540;
	//myCode.m_code.pulses[16].lowValue = 480;
	//myCode.m_code.pulses[17].highValue = 540;
	//myCode.m_code.pulses[17].lowValue = 1530;
	//myCode.m_code.pulses[18].highValue = 540;
	//myCode.m_code.pulses[18].lowValue = 1530;
	//myCode.m_code.pulses[19].highValue = 540;
	//myCode.m_code.pulses[19].lowValue = 1500;
	//myCode.m_code.pulses[20].highValue = 540;
	//myCode.m_code.pulses[20].lowValue = 480;
	//myCode.m_code.pulses[21].highValue = 540;
	//myCode.m_code.pulses[21].lowValue = 480;
	//myCode.m_code.pulses[22].highValue = 540;
	//myCode.m_code.pulses[22].lowValue = 480;
	//myCode.m_code.pulses[23].highValue = 540;
	//myCode.m_code.pulses[23].lowValue = 480;
	//myCode.m_code.pulses[24].highValue = 540;
	//myCode.m_code.pulses[24].lowValue = 480;
	//myCode.m_code.pulses[25].highValue = 540;
	//myCode.m_code.pulses[25].lowValue = 480;
	//myCode.m_code.pulses[26].highValue = 540;
	//myCode.m_code.pulses[26].lowValue = 480;
	//myCode.m_code.pulses[27].highValue = 510;
	//myCode.m_code.pulses[27].lowValue = 480;
	//myCode.m_code.pulses[28].highValue = 540;
	//myCode.m_code.pulses[28].lowValue = 1530;
	//myCode.m_code.pulses[29].highValue = 540;
	//myCode.m_code.pulses[29].lowValue = 1530;
	//myCode.m_code.pulses[30].highValue = 540;
	//myCode.m_code.pulses[30].lowValue = 1500;
	//myCode.m_code.pulses[31].highValue = 570;
	//myCode.m_code.pulses[31].lowValue = 1500;
	//myCode.m_code.pulses[32].highValue = 540;
	//myCode.m_code.pulses[32].lowValue = 1530;
	//myCode.m_code.pulses[33].highValue = 540;
	//myCode.m_code.pulses[33].lowValue = 43650;
	//myCode.m_code.pulses[34].highValue = 4140;
	//myCode.m_code.pulses[34].lowValue = 4140;
	//myCode.m_code.pulses[35].highValue = 540;
	//myCode.m_code.pulses[35].lowValue = 1530;
	//myCode.m_code.pulses[36].highValue = 540;
	//myCode.m_code.pulses[36].lowValue = 1530;
	//myCode.m_code.pulses[37].highValue = 540;
	//myCode.m_code.pulses[37].lowValue = 1500;
	//myCode.m_code.pulses[38].highValue = 570;
	//myCode.m_code.pulses[38].lowValue = 450;
	//myCode.m_code.pulses[39].highValue = 540;
	//myCode.m_code.pulses[39].lowValue = 480;
	//myCode.m_code.pulses[40].highValue = 540;
	//myCode.m_code.pulses[40].lowValue = 480;
	//myCode.m_code.pulses[41].highValue = 540;
	//myCode.m_code.pulses[41].lowValue = 480;
	//myCode.m_code.pulses[42].highValue = 540;
	//myCode.m_code.pulses[42].lowValue = 480;
	//myCode.m_code.pulses[43].highValue = 540;
	//myCode.m_code.pulses[43].lowValue = 1530;
	//myCode.m_code.pulses[44].highValue = 540;
	//myCode.m_code.pulses[44].lowValue = 1500;
	//myCode.m_code.pulses[45].highValue = 540;
	//myCode.m_code.pulses[45].lowValue = 1530;
	//myCode.m_code.pulses[46].highValue = 540;
	//myCode.m_code.pulses[46].lowValue = 480;
	//myCode.m_code.pulses[47].highValue = 540;
	//myCode.m_code.pulses[47].lowValue = 480;
	//myCode.m_code.pulses[48].highValue = 540;
	//myCode.m_code.pulses[48].lowValue = 480;
	//myCode.m_code.pulses[49].highValue = 510;
	//myCode.m_code.pulses[49].lowValue = 510;
	//myCode.m_code.pulses[50].highValue = 510;
	//myCode.m_code.pulses[50].lowValue = 480;
	//myCode.m_code.pulses[51].highValue = 540;
	//myCode.m_code.pulses[51].lowValue = 1530;
	//myCode.m_code.pulses[52].highValue = 540;
	//myCode.m_code.pulses[52].lowValue = 1530;
	//myCode.m_code.pulses[53].highValue = 540;
	//myCode.m_code.pulses[53].lowValue = 1500;
	//myCode.m_code.pulses[54].highValue = 570;
	//myCode.m_code.pulses[54].lowValue = 450;
	//myCode.m_code.pulses[55].highValue = 540;
	//myCode.m_code.pulses[55].lowValue = 480;
	//myCode.m_code.pulses[56].highValue = 540;
	//myCode.m_code.pulses[56].lowValue = 480;
	//myCode.m_code.pulses[57].highValue = 540;
	//myCode.m_code.pulses[57].lowValue = 480;
	//myCode.m_code.pulses[58].highValue = 540;
	//myCode.m_code.pulses[58].lowValue = 480;
	//myCode.m_code.pulses[59].highValue = 540;
	//myCode.m_code.pulses[59].lowValue = 480;
	//myCode.m_code.pulses[60].highValue = 540;
	//myCode.m_code.pulses[60].lowValue = 480;
	//myCode.m_code.pulses[61].highValue = 540;
	//myCode.m_code.pulses[61].lowValue = 450;
	//myCode.m_code.pulses[62].highValue = 540;
	//myCode.m_code.pulses[62].lowValue = 1530;
	//myCode.m_code.pulses[63].highValue = 540;
	//myCode.m_code.pulses[63].lowValue = 1530;
	//myCode.m_code.pulses[64].highValue = 540;
	//myCode.m_code.pulses[64].lowValue = 1500;
	//myCode.m_code.pulses[65].highValue = 540;
	//myCode.m_code.pulses[65].lowValue = 1530;
	//myCode.m_code.pulses[66].highValue = 540;
	//myCode.m_code.pulses[66].lowValue = 1530;
	//myCode.m_code.pulses[67].highValue = 540;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 9:
	////Volume -:
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4140;
	//myCode.m_code.pulses[0].lowValue = 4140;
	//myCode.m_code.pulses[1].highValue = 570;
	//myCode.m_code.pulses[1].lowValue = 1500;
	//myCode.m_code.pulses[2].highValue = 540;
	//myCode.m_code.pulses[2].lowValue = 1530;
	//myCode.m_code.pulses[3].highValue = 540;
	//myCode.m_code.pulses[3].lowValue = 1530;
	//myCode.m_code.pulses[4].highValue = 540;
	//myCode.m_code.pulses[4].lowValue = 480;
	//myCode.m_code.pulses[5].highValue = 540;
	//myCode.m_code.pulses[5].lowValue = 480;
	//myCode.m_code.pulses[6].highValue = 510;
	//myCode.m_code.pulses[6].lowValue = 480;
	//myCode.m_code.pulses[7].highValue = 540;
	//myCode.m_code.pulses[7].lowValue = 480;
	//myCode.m_code.pulses[8].highValue = 540;
	//myCode.m_code.pulses[8].lowValue = 480;
	//myCode.m_code.pulses[9].highValue = 540;
	//myCode.m_code.pulses[9].lowValue = 1530;
	//myCode.m_code.pulses[10].highValue = 540;
	//myCode.m_code.pulses[10].lowValue = 1500;
	//myCode.m_code.pulses[11].highValue = 540;
	//myCode.m_code.pulses[11].lowValue = 1530;
	//myCode.m_code.pulses[12].highValue = 540;
	//myCode.m_code.pulses[12].lowValue = 480;
	//myCode.m_code.pulses[13].highValue = 540;
	//myCode.m_code.pulses[13].lowValue = 480;
	//myCode.m_code.pulses[14].highValue = 540;
	//myCode.m_code.pulses[14].lowValue = 480;
	//myCode.m_code.pulses[15].highValue = 540;
	//myCode.m_code.pulses[15].lowValue = 480;
	//myCode.m_code.pulses[16].highValue = 540;
	//myCode.m_code.pulses[16].lowValue = 480;
	//myCode.m_code.pulses[17].highValue = 540;
	//myCode.m_code.pulses[17].lowValue = 1500;
	//myCode.m_code.pulses[18].highValue = 540;
	//myCode.m_code.pulses[18].lowValue = 1530;
	//myCode.m_code.pulses[19].highValue = 540;
	//myCode.m_code.pulses[19].lowValue = 480;
	//myCode.m_code.pulses[20].highValue = 540;
	//myCode.m_code.pulses[20].lowValue = 1530;
	//myCode.m_code.pulses[21].highValue = 540;
	//myCode.m_code.pulses[21].lowValue = 480;
	//myCode.m_code.pulses[22].highValue = 510;
	//myCode.m_code.pulses[22].lowValue = 480;
	//myCode.m_code.pulses[23].highValue = 540;
	//myCode.m_code.pulses[23].lowValue = 480;
	//myCode.m_code.pulses[24].highValue = 540;
	//myCode.m_code.pulses[24].lowValue = 480;
	//myCode.m_code.pulses[25].highValue = 540;
	//myCode.m_code.pulses[25].lowValue = 480;
	//myCode.m_code.pulses[26].highValue = 540;
	//myCode.m_code.pulses[26].lowValue = 480;
	//myCode.m_code.pulses[27].highValue = 540;
	//myCode.m_code.pulses[27].lowValue = 1500;
	//myCode.m_code.pulses[28].highValue = 540;
	//myCode.m_code.pulses[28].lowValue = 480;
	//myCode.m_code.pulses[29].highValue = 540;
	//myCode.m_code.pulses[29].lowValue = 1530;
	//myCode.m_code.pulses[30].highValue = 540;
	//myCode.m_code.pulses[30].lowValue = 1530;
	//myCode.m_code.pulses[31].highValue = 540;
	//myCode.m_code.pulses[31].lowValue = 1500;
	//myCode.m_code.pulses[32].highValue = 540;
	//myCode.m_code.pulses[32].lowValue = 1530;
	//myCode.m_code.pulses[33].highValue = 540;
	//myCode.m_code.pulses[33].lowValue = 43650;
	//myCode.m_code.pulses[34].highValue = 4140;
	//myCode.m_code.pulses[34].lowValue = 4140;
	//myCode.m_code.pulses[35].highValue = 540;
	//myCode.m_code.pulses[35].lowValue = 1530;
	//myCode.m_code.pulses[36].highValue = 540;
	//myCode.m_code.pulses[36].lowValue = 1530;
	//myCode.m_code.pulses[37].highValue = 540;
	//myCode.m_code.pulses[37].lowValue = 1500;
	//myCode.m_code.pulses[38].highValue = 540;
	//myCode.m_code.pulses[38].lowValue = 480;
	//myCode.m_code.pulses[39].highValue = 540;
	//myCode.m_code.pulses[39].lowValue = 480;
	//myCode.m_code.pulses[40].highValue = 540;
	//myCode.m_code.pulses[40].lowValue = 480;
	//myCode.m_code.pulses[41].highValue = 540;
	//myCode.m_code.pulses[41].lowValue = 480;
	//myCode.m_code.pulses[42].highValue = 540;
	//myCode.m_code.pulses[42].lowValue = 480;
	//myCode.m_code.pulses[43].highValue = 540;
	//myCode.m_code.pulses[43].lowValue = 1500;
	//myCode.m_code.pulses[44].highValue = 540;
	//myCode.m_code.pulses[44].lowValue = 1530;
	//myCode.m_code.pulses[45].highValue = 540;
	//myCode.m_code.pulses[45].lowValue = 1530;
	//myCode.m_code.pulses[46].highValue = 540;
	//myCode.m_code.pulses[46].lowValue = 480;
	//myCode.m_code.pulses[47].highValue = 540;
	//myCode.m_code.pulses[47].lowValue = 480;
	//myCode.m_code.pulses[48].highValue = 540;
	//myCode.m_code.pulses[48].lowValue = 450;
	//myCode.m_code.pulses[49].highValue = 570;
	//myCode.m_code.pulses[49].lowValue = 450;
	//myCode.m_code.pulses[50].highValue = 540;
	//myCode.m_code.pulses[50].lowValue = 480;
	//myCode.m_code.pulses[51].highValue = 540;
	//myCode.m_code.pulses[51].lowValue = 1530;
	//myCode.m_code.pulses[52].highValue = 540;
	//myCode.m_code.pulses[52].lowValue = 1530;
	//myCode.m_code.pulses[53].highValue = 540;
	//myCode.m_code.pulses[53].lowValue = 480;
	//myCode.m_code.pulses[54].highValue = 510;
	//myCode.m_code.pulses[54].lowValue = 1530;
	//myCode.m_code.pulses[55].highValue = 540;
	//myCode.m_code.pulses[55].lowValue = 480;
	//myCode.m_code.pulses[56].highValue = 540;
	//myCode.m_code.pulses[56].lowValue = 480;
	//myCode.m_code.pulses[57].highValue = 540;
	//myCode.m_code.pulses[57].lowValue = 480;
	//myCode.m_code.pulses[58].highValue = 540;
	//myCode.m_code.pulses[58].lowValue = 480;
	//myCode.m_code.pulses[59].highValue = 540;
	//myCode.m_code.pulses[59].lowValue = 480;
	//myCode.m_code.pulses[60].highValue = 510;
	//myCode.m_code.pulses[60].lowValue = 480;
	//myCode.m_code.pulses[61].highValue = 540;
	//myCode.m_code.pulses[61].lowValue = 1530;
	//myCode.m_code.pulses[62].highValue = 540;
	//myCode.m_code.pulses[62].lowValue = 480;
	//myCode.m_code.pulses[63].highValue = 540;
	//myCode.m_code.pulses[63].lowValue = 1500;
	//myCode.m_code.pulses[64].highValue = 570;
	//myCode.m_code.pulses[64].lowValue = 1500;
	//myCode.m_code.pulses[65].highValue = 540;
	//myCode.m_code.pulses[65].lowValue = 1530;
	//myCode.m_code.pulses[66].highValue = 540;
	//myCode.m_code.pulses[66].lowValue = 1530;
	//myCode.m_code.pulses[67].highValue = 540;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//
	//case 10:
	////Liga/Desliga radio(home T.):
	////Codes captured: 68
	//myCode.m_code.size = 68;
	//myCode.m_code.pulses[0].highValue = 4170;
	//myCode.m_code.pulses[0].lowValue = 4140;
	//myCode.m_code.pulses[1].highValue = 570;
	//myCode.m_code.pulses[1].lowValue = 1500;
	//myCode.m_code.pulses[2].highValue = 540;
	//myCode.m_code.pulses[2].lowValue = 1530;
	//myCode.m_code.pulses[3].highValue = 570;
	//myCode.m_code.pulses[3].lowValue = 450;
	//myCode.m_code.pulses[4].highValue = 570;
	//myCode.m_code.pulses[4].lowValue = 450;
	//myCode.m_code.pulses[5].highValue = 540;
	//myCode.m_code.pulses[5].lowValue = 480;
	//myCode.m_code.pulses[6].highValue = 540;
	//myCode.m_code.pulses[6].lowValue = 480;
	//myCode.m_code.pulses[7].highValue = 510;
	//myCode.m_code.pulses[7].lowValue = 1560;
	//myCode.m_code.pulses[8].highValue = 540;
	//myCode.m_code.pulses[8].lowValue = 480;
	//myCode.m_code.pulses[9].highValue = 540;
	//myCode.m_code.pulses[9].lowValue = 1530;
	//myCode.m_code.pulses[10].highValue = 570;
	//myCode.m_code.pulses[10].lowValue = 1500;
	//myCode.m_code.pulses[11].highValue = 570;
	//myCode.m_code.pulses[11].lowValue = 450;
	//myCode.m_code.pulses[12].highValue = 570;
	//myCode.m_code.pulses[12].lowValue = 450;
	//myCode.m_code.pulses[13].highValue = 540;
	//myCode.m_code.pulses[13].lowValue = 1530;
	//myCode.m_code.pulses[14].highValue = 540;
	//myCode.m_code.pulses[14].lowValue = 480;
	//myCode.m_code.pulses[15].highValue = 570;
	//myCode.m_code.pulses[15].lowValue = 1500;
	//myCode.m_code.pulses[16].highValue = 570;
	//myCode.m_code.pulses[16].lowValue = 450;
	//myCode.m_code.pulses[17].highValue = 540;
	//myCode.m_code.pulses[17].lowValue = 1530;
	//myCode.m_code.pulses[18].highValue = 570;
	//myCode.m_code.pulses[18].lowValue = 450;
	//myCode.m_code.pulses[19].highValue = 570;
	//myCode.m_code.pulses[19].lowValue = 450;
	//myCode.m_code.pulses[20].highValue = 540;
	//myCode.m_code.pulses[20].lowValue = 480;
	//myCode.m_code.pulses[21].highValue = 510;
	//myCode.m_code.pulses[21].lowValue = 480;
	//myCode.m_code.pulses[22].highValue = 540;
	//myCode.m_code.pulses[22].lowValue = 480;
	//myCode.m_code.pulses[23].highValue = 570;
	//myCode.m_code.pulses[23].lowValue = 450;
	//myCode.m_code.pulses[24].highValue = 570;
	//myCode.m_code.pulses[24].lowValue = 450;
	//myCode.m_code.pulses[25].highValue = 540;
	//myCode.m_code.pulses[25].lowValue = 450;
	//myCode.m_code.pulses[26].highValue = 540;
	//myCode.m_code.pulses[26].lowValue = 1560;
	//myCode.m_code.pulses[27].highValue = 540;
	//myCode.m_code.pulses[27].lowValue = 1530;
	//myCode.m_code.pulses[28].highValue = 570;
	//myCode.m_code.pulses[28].lowValue = 1500;
	//myCode.m_code.pulses[29].highValue = 570;
	//myCode.m_code.pulses[29].lowValue = 1530;
	//myCode.m_code.pulses[30].highValue = 540;
	//myCode.m_code.pulses[30].lowValue = 1530;
	//myCode.m_code.pulses[31].highValue = 570;
	//myCode.m_code.pulses[31].lowValue = 1500;
	//myCode.m_code.pulses[32].highValue = 570;
	//myCode.m_code.pulses[32].lowValue = 1530;
	//myCode.m_code.pulses[33].highValue = 540;
	//myCode.m_code.pulses[33].lowValue = 42810;
	//myCode.m_code.pulses[34].highValue = 4140;
	//myCode.m_code.pulses[34].lowValue = 4170;
	//myCode.m_code.pulses[35].highValue = 570;
	//myCode.m_code.pulses[35].lowValue = 1530;
	//myCode.m_code.pulses[36].highValue = 510;
	//myCode.m_code.pulses[36].lowValue = 1560;
	//myCode.m_code.pulses[37].highValue = 570;
	//myCode.m_code.pulses[37].lowValue = 450;
	//myCode.m_code.pulses[38].highValue = 540;
	//myCode.m_code.pulses[38].lowValue = 450;
	//myCode.m_code.pulses[39].highValue = 540;
	//myCode.m_code.pulses[39].lowValue = 480;
	//myCode.m_code.pulses[40].highValue = 540;
	//myCode.m_code.pulses[40].lowValue = 480;
	//myCode.m_code.pulses[41].highValue = 540;
	//myCode.m_code.pulses[41].lowValue = 1530;
	//myCode.m_code.pulses[42].highValue = 540;
	//myCode.m_code.pulses[42].lowValue = 480;
	//myCode.m_code.pulses[43].highValue = 540;
	//myCode.m_code.pulses[43].lowValue = 1530;
	//myCode.m_code.pulses[44].highValue = 540;
	//myCode.m_code.pulses[44].lowValue = 1560;
	//myCode.m_code.pulses[45].highValue = 540;
	//myCode.m_code.pulses[45].lowValue = 450;
	//myCode.m_code.pulses[46].highValue = 540;
	//myCode.m_code.pulses[46].lowValue = 480;
	//myCode.m_code.pulses[47].highValue = 540;
	//myCode.m_code.pulses[47].lowValue = 1530;
	//myCode.m_code.pulses[48].highValue = 570;
	//myCode.m_code.pulses[48].lowValue = 450;
	//myCode.m_code.pulses[49].highValue = 540;
	//myCode.m_code.pulses[49].lowValue = 1560;
	//myCode.m_code.pulses[50].highValue = 540;
	//myCode.m_code.pulses[50].lowValue = 450;
	//myCode.m_code.pulses[51].highValue = 540;
	//myCode.m_code.pulses[51].lowValue = 1560;
	//myCode.m_code.pulses[52].highValue = 540;
	//myCode.m_code.pulses[52].lowValue = 450;
	//myCode.m_code.pulses[53].highValue = 540;
	//myCode.m_code.pulses[53].lowValue = 480;
	//myCode.m_code.pulses[54].highValue = 540;
	//myCode.m_code.pulses[54].lowValue = 480;
	//myCode.m_code.pulses[55].highValue = 540;
	//myCode.m_code.pulses[55].lowValue = 480;
	//myCode.m_code.pulses[56].highValue = 540;
	//myCode.m_code.pulses[56].lowValue = 480;
	//myCode.m_code.pulses[57].highValue = 540;
	//myCode.m_code.pulses[57].lowValue = 450;
	//myCode.m_code.pulses[58].highValue = 540;
	//myCode.m_code.pulses[58].lowValue = 480;
	//myCode.m_code.pulses[59].highValue = 570;
	//myCode.m_code.pulses[59].lowValue = 450;
	//myCode.m_code.pulses[60].highValue = 540;
	//myCode.m_code.pulses[60].lowValue = 1530;
	//myCode.m_code.pulses[61].highValue = 570;
	//myCode.m_code.pulses[61].lowValue = 1500;
	//myCode.m_code.pulses[62].highValue = 540;
	//myCode.m_code.pulses[62].lowValue = 1560;
	//myCode.m_code.pulses[63].highValue = 540;
	//myCode.m_code.pulses[63].lowValue = 1530;
	//myCode.m_code.pulses[64].highValue = 570;
	//myCode.m_code.pulses[64].lowValue = 1530;
	//myCode.m_code.pulses[65].highValue = 540;
	//myCode.m_code.pulses[65].lowValue = 1530;
	//myCode.m_code.pulses[66].highValue = 540;
	//myCode.m_code.pulses[66].lowValue = 1530;
	//myCode.m_code.pulses[67].highValue = 570;
	//myCode.m_code.pulses[67].lowValue = 0;
	//myCode.play(IRLedEmiterPin);
	//TVTimer.presetTime = 1500;
	//IRControlCase = 15; //Go to default step.
	//break;
	//case 15:
	//TVTimer.start();
	//if (TVTimer.done())
	//{
		//TVTimer.stop();
		//IRControlCase = 0; //Go to default step.
	//}
	//break;
	//
	//
	//default:
	////Default step:
	//break;
//}
//
//
////------------------------- Main Program -------------------------	
//
////------------------------- Output Mirror -------------------------	
	//digitalWrite(ledGreenPin, ledGreen);
	//digitalWrite(ledYellowPin, ledYellow);
	//digitalWrite(ledRedPin, ledRed);
	//digitalWrite(IRLedEmiterPin, IRLedEmiter);
////------------------------- Output Mirror -------------------------	
//}
//


/*
  Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts, 
 so only the following can be used for RX: 
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts, 
 so only the following can be used for RX: 
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */

#include "SoftwareSerial.h"
#include <stdint.h>

//char abc = 10;
//
//SoftwareSerial mySerial(10, 11); // RX, TX
//
//void setup()  
//{
  //// Open serial communications and wait for port to open:
  //Serial.begin(9600);
  //while (!Serial) {
    //; // wait for serial port to connect. Needed for Leonardo only
  //}
//
//
  //Serial.println("Goodnight moon!");
//
  //// set the data rate for the SoftwareSerial port
  //mySerial.begin(9600);
  //mySerial.println("Hello, world?");
//}
//
//void loop() // run over and over
//{
  //if (mySerial.available())
  //Serial.write(mySerial.read());
  //if (Serial.available())
  //mySerial.write(Serial.read());
//}



/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */
 
//#include "SD\SD.h"
//
//File myFile;
//
//void setup()
//{
 //// Open serial communications and wait for port to open:
  //Serial.begin(9600);
   //while (!Serial) {
    //; // wait for serial port to connect. Needed for Leonardo only
  //}
//
//
  //Serial.print("Initializing SD card...");
  //// On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  //// Note that even if it's not used as the CS pin, the hardware SS pin 
  //// (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  //// or the SD library functions will not work. 
   //pinMode(10, OUTPUT);
   //
  //if (!SD.begin(4)) {
    //Serial.println("initialization failed!");
    //return;
  //}
  //Serial.println("initialization done.");
  //
  //// open the file. note that only one file can be open at a time,
  //// so you have to close this one before opening another.
  //myFile = SD.open("test.txt", FILE_WRITE);
  //
  //// if the file opened okay, write to it:
  //if (myFile) {
    //Serial.print("Writing to test.txt...");
    //myFile.println("testing a, b, c.");
	//// close the file:
    //myFile.close();
    //Serial.println("done.");
  //} else {
    //// if the file didn't open, print an error:
    //Serial.println("error opening test.txt");
  //}
  //
  //// re-open the file for reading:
  //myFile = SD.open("test.txt");
  //if (myFile) {
    //Serial.println("test.txt:");
    //
    //// read from the file until there's nothing else in it:
    //while (myFile.available()) {
    	//Serial.write(myFile.read());
    //}
    //// close the file:
    //myFile.close();
  //} else {
  	//// if the file didn't open, print an error:
    //Serial.println("error opening test.txt");
  //}
//}
//
//void loop()
//{
	//// nothing happens after setup
//}


#include "Arduino.h"
#include "EDB/EDB.h"
#include <SD.h>

File dbFile;

#define TABLE_SIZE 512
#define RECORDS_TO_CREATE 15

struct LogEvent {
	int id;
	int temperature;
}
logEvent;

void writer(unsigned long address, byte data)
{
	dbFile.seek(address);
	dbFile.write(data);
	dbFile.flush();
}

byte reader(unsigned long address)
{
	dbFile.seek(address);
	return dbFile.read();
}


EDB db(&writer, &reader);

void setup()
{
	Serial.begin(9600);
	
	Serial.print("Initializing SD card...");
	
	pinMode(10, OUTPUT);
	
	if (!SD.begin()) {
		Serial.println("initialization failed!");
		return;
	}
	
	Serial.println("initialization done.");
	
	Serial.println("Opening example.db ...");
	dbFile = SD.open("example.db", FILE_READ);
	
	
	Serial.println(db.count(), DEC);
	//db.create(0, TABLE_SIZE, sizeof(logEvent));
	
	Serial.print("Record Count: "); Serial.println(db.count());
	
	Serial.println("Creating Records...");
	int recno;
	//for (recno = 1; recno <= RECORDS_TO_CREATE; recno++)
	//{
		//logEvent.id = recno;
		//logEvent.temperature = recno * 2;
		//db.appendRec(EDB_REC logEvent);
		//if (recno == 5)
		//{
			//db.deleteRec(recno);
			//
		//}
	//}
	
	Serial.print("Record Count: "); Serial.println(db.count());
	for (recno = 1; recno < db.count(); recno++)
	{
		db.readRec(recno, EDB_REC logEvent);
		Serial.print("ID: "); Serial.println(logEvent.id);
		Serial.print("Temp: "); Serial.println(logEvent.temperature);
		
	}
}


void loop()
{
	
}