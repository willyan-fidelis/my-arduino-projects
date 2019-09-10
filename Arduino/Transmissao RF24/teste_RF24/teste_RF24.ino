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

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"


RF24 radio(9,10);
boolean SendDone = 0;

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
  
  
}

void loop(void)
{
  delay (800); 
  radio.stopListening();
    
    
    unsigned long time = 112233;
    printf("sending %lu...",time);
    bool ok = radio.write( &time, sizeof(unsigned long) );
    
    
    if (ok)
      {
      printf("ok...\n\r");
      SendDone = 1;
      }
    else
      {
      printf("failed.\n\r");
      SendDone = 1;
      }

      
  if ( SendDone == 1 )
      {   
       delay (800); 
       radio.startListening();
     
        if ( radio.available() )
           {
           unsigned long got_time;
           radio.read( &got_time, sizeof(unsigned long) );
           printf(" %lu\n\r",got_time);
           }
        SendDone = 0;
     }
      delay(100);
}

   

    
