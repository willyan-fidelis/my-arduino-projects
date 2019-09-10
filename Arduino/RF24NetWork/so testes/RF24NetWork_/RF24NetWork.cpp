//Class RF24NetWork

#include "RF24NetWork.h"


NR24NetWork::NR24NetWork(int _Mode, byte * &_ptData, int _DataSize)//NR24NetWork(int _Mode, byte * _ptData, int _DataSize) //uint8_t
{
  _ptData=(byte*)::malloc(sizeof(NR24NetWorkHeader) + _DataSize);
  m_ptHeader = _ptData + sizeof(NR24NetWorkHeader);
  m_ptData = _ptData;
  
  
  //Serial.println((int)m_ptData);
    
  
  Mirf.csnPin = 10;
  Mirf.cePin = 9;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init(); 
  NR24NetWork::setDeviceMode(_Mode);
  setPayLoadSize(_DataSize);
  Mirf.config();
}

void NR24NetWork::setPayLoadSize(byte _DataSize)
{
  m_dataSize = _DataSize + sizeof(NR24NetWorkHeader);
  Mirf.payload = m_dataSize;
  //Serial.println(m_dataSize);
}

void NR24NetWork::setDeviceMode(int _Mode)
{
  //Serial.println(*m_ptData);
  
  m_mode = _Mode;
  //------------ Set the real address acordding ------------
  if (PASSIVE_MODE == _Mode)
  {
    Mirf.setTADDR((byte *)"00");
    Mirf.setRADDR((byte *)"00");
    Serial.println("Device Mode: PASSIVE");
  }
  if (READER_MODE == _Mode)
  {
    Mirf.setTADDR((byte *)"00");
    Mirf.setRADDR((byte *)"01");
    Serial.println("Device Mode: READER");
  }
  if (WRITER_MODE == _Mode)
  {
    Mirf.setTADDR((byte *)"01");
    Mirf.setRADDR((byte *)"00");
    Serial.println("Device Mode: WRITER");
  }
  if (SLAVE_MODE == _Mode)
  {
    Mirf.setTADDR((byte *)"02");
    Mirf.setRADDR((byte *)"03");
    Serial.println("Device Mode: SLAVE");
  }
  if (MASTER_MODE == _Mode)
  {
    Mirf.setTADDR((byte *)"03");
    Mirf.setRADDR((byte *)"02");
    Serial.println("Device Mode: MASTER");
  }
  //------------ Set the real address acordding ------------
}

int NR24NetWork::getDeviceMode()
{
  return m_mode;
}


//------------------------------ write() -----------------------------
bool NR24NetWork::write(int _Node)
{ 
  //Serial.println((int)m_ptData);
  //Serial.println(m_dataSize);
  //Serial.println(Mirf.payload);
  
  int m_sc = 1;
  m_tmrFaultTMO.stop();
  while(true)
  {
  switch (m_sc)
  {
    case 01: //Step 01 - Wait the RF24 is not sending to start the comunication.
      m_tmrFaultTMO.start();
      
      if(!Mirf.isSending())
      {
        //*m_ptData = 100;
        Mirf.send((byte *)&(*m_ptData));
        //Mirf.send((byte *)&test);
      }
      if(Mirf.isSending())
      {
        m_tmrFaultTMO.stop();
        m_sc = 10;
      }
      if (m_tmrFaultTMO.done())
      {
        return false;
      }
      break;
    case 10: //Step 100 - Wait it finishes.
      m_tmrFaultTMO.start();
      if(!Mirf.isSending())
      {
        m_tmrFaultTMO.stop();
        m_sc = 100;
      }
      if (m_tmrFaultTMO.done())
      {
        m_tmrFaultTMO.stop();
        m_sc = 200;
      }      
      break;
    case 100: //Step 100 - Every things was fine.
      Serial.println("Write was good!");
      return true;
      break;
    case 200: //Step 200 - Every things was bad.
      Serial.println("Write was bad!");
      return false;
      break;
  }
  
  }
}
//------------------------------ write() -----------------------------

//------------------------------ read() ------------------------------
bool NR24NetWork::read()
{
  //Serial.println((int)m_ptData);
  //Serial.println(Mirf.payload);
  
  int m_sc = 1;
  m_tmrFaultTMO.stop();
  while(true)
  {
  switch (m_sc)
  {
    case 01: //Step 01 - Wait the RF24 is not sending to start the comunication.
      m_tmrFaultTMO.start(5000);
      
      if (!Mirf.dataReady())
      {
        Serial.println("No data available!");
        return false;
      }
      
      if(!Mirf.isSending() && Mirf.dataReady())
      {
        Mirf.getData((byte *)&(*m_ptData));
        //Mirf.getData((byte *)&test);
        //Serial.println(*m_ptData);
        
        m_tmrFaultTMO.stop();
        m_sc = 10;
      }
      //if(Mirf.isSending())
      //{
      //  m_sc = 200;
      //}
      if (m_tmrFaultTMO.done())
      {
        m_sc = 200;
      }
      break;
    case 10: //Step 10 - Wait it finishes.
      m_sc = 100;  
      break;
    case 100: //Step 20 - Every things was fine.
      Serial.println("Read was good!");
      Mirf.flushRx();
      return true;
      break;
    case 200: //Step 30 - Every things was bad.
      Serial.println("Read was bad!");
      return false;
      break;
  }
  
  }
}
//------------------------------ read() ------------------------------
