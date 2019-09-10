//Header file

#ifndef _NR24NETWORK_H
#define _NR24NETWORK_H

#include <Arduino.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <Timer.h>

//Define all possibles operation modes:
#define PASSIVE_MODE  0
#define READER_MODE   1
#define WRITER_MODE   2
#define SLAVE_MODE    3
#define MASTER_MODE   4

//
#define ALL     -100

struct NR24NetWorkHeader {
  int m_DeviceMode;
  int m_NetWorkIdent;
  int m_NodeAddress;
  int m_LastPartnerIdent;
  int m_HS;
  //int password;
};

class NR24NetWork //: Nrf24l
{
public:
NR24NetWork(int _Mode, byte * &_ptData, int _DataSize);//NR24NetWork(int _Mode, byte * _ptData, int _DataSize);
void setDeviceMode(int _Mode);
int getDeviceMode();
void setNetWorkIdent(int _NetWorkID);
int getNetWorkIdent();
void setNodeAddress();
int getNodeAddress();
void setPayLoadSize(byte _DataSize);
int getPayLoadSize();
void getActHS();
void getPayLoad();
bool findOutAddress();                  //Find out an available address and so auto configure with it.
bool pingWith(int _Node);
void setComunicationFaultTMO(int _tmo);

bool write(int _Node);
bool read();
bool writeWithHS(int _Node);
bool readWithHS();


private:
//----- Communication Header -----
NR24NetWorkHeader * m_communicationHeader;
NR24NetWorkHeader * m_ComHeaderOtherPartner;
//----- Communication Header -----

Timer m_tmrFaultTMO;

int m_mode;
byte m_dataSize;

byte * m_ptData;//uint8_t * m_ptData;
byte * m_ptHeader;

byte test;

};
#endif
