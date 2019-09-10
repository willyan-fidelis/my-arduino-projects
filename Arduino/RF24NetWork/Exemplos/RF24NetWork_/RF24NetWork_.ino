#include "RF24NetWork.h"  //Local header
#include <SPI.h>
#include "Mirf.h"
//#include <nRF24L01.h>
//#include <MirfHardwareSpiDriver.h>
#include <MathUtilities.h>
#include <Timer.h>
#include <avr/wdt.h> //Include watchdog timer
#include <stdlib.h> // for malloc and free
//Ethernet module ENC28J60 library:
#include <EtherCard.h>

//Ethernet tags -------------------
#define REQUEST_RATE 5000 // milliseconds

// ethernet interface mac address
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };
//static byte myip[] = { 192,168,0,201 };
// remote website name
const char website[] PROGMEM = "google.com";

byte Ethernet::buffer[700];
BufferFiller bfill;
//static long timer;
//Ethernet tags -------------------

struct DataToComunicatioTest {
  int HS;
  int Speed;
  int Position;
  boolean LampTurnedOn;
};

struct GeneralDevice {
  int Type;
  int PType;
  int Status;
  int Cmd;
  int Parammeter[5];
};

DataToComunicatioTest * RF24Data;
byte * ptrbyte;

NR24NetWork NR24Node((byte*&)RF24Data, sizeof(DataToComunicatioTest));

static word homePage() {
  long t = millis() / 1000;
  word h = t / 3600;
  byte m = (t / 60) % 60;
  byte s = t % 60;
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Pragma: no-cache\r\n"
    "\r\n"
    "<meta http-equiv='refresh' content='1'/>"
    "<title>RBBB server</title>" 
    "<img src=http://www.w3schools.com/html/w3schools.jpg width=104 height=142>"
    "<h1>$D$D:$D$D:$D$D</h1>"
    "<?php"
    "$number = 9;"
    "$str = Beijing;"
    "printf(There are %u million bicycles in %s.,$number,$str);"
    "?>"
    ),
    
      h/10, h%10, m/10, m%10, s/10, s%10);
  return bfill.position();
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Data size: ");Serial.println(NR24Node.getPayLoadSize());
  pinMode(3, INPUT);
  
  //Ethernet setup ------------
  Serial.println("\n[getDHCPandDNS]");
  
  if (ether.begin(sizeof (Ethernet::buffer), mymac, 8) == 0) 
  {
    Serial.println( "Failed to access Ethernet controller");
  }
  else
    {
    if (!ether.dhcpSetup())//(!ether.staticSetup(myip))
    {
      Serial.println("DHCP failed");
    }
    else
    {
      Serial.println("DHCP ok");
      ether.printIp("My IP: ", ether.myip);
      // ether.printIp("Netmask: ", ether.mymask);
      ether.printIp("GW IP: ", ether.gwip);
      ether.printIp("DNS IP: ", ether.dnsip);
    }
  
    if (!ether.dnsLookup(website))
    {
      Serial.println("DNS failed");
    }
    else
    {
      Serial.println("DNS ok");
      ether.printIp("Server: ", ether.hisip);
    }
  }
  //Ethernet setup ------------
}

void loop()
{
  /*
  Timer m_tmrFaultTMO;
  
  while (true)
  {
  m_tmrFaultTMO.start(3000);
  if (m_tmrFaultTMO.done())
  {
    Serial.println("One seconded elapsed!");
    //m_tmrFaultTMO.stop();
    return;
  }
  }
  */
  
  //----------- Mode Selection -----------
  if (Serial.available() )
  {
  while (Serial.available() > 0)
  {
     char incomingChar = Serial.read();
     if (incomingChar == 'w')
     {
       //NR24Node.SndData(EMPTY_ADDRESS, "1234");
       
       if (NR24Node.SndAskData(EMPTY_ADDRESS, "1234") == VALID)
       {
         if (RF24Data->LampTurnedOn)
         {
           Serial.println("Lamp Turned On!");
         }
         else
         {
           Serial.println("Lamp Turned off!");
         }
       }
     }
     if (incomingChar == 'r')
     {
       while(true)
       {
       NR24Node.recive();
       
       RF24Data->LampTurnedOn = digitalRead(3);
       NR24Node.SndAnswerData();
       }
     }
     if (incomingChar == '1')
     {
     }
     if (incomingChar == '2')
     {
     }
  }
  }
  //----------- Mode Selection -----------
  
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  
  if (pos)  // check if valid tcp data is received
  {
    ether.httpServerReply(homePage()); // send web page data
  }
  
}
