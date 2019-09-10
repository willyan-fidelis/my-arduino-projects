//Class RF24NetWork

#include "RF24NetWork.h"
#include <stdlib.h> // for malloc and free


NR24NetWork::NR24NetWork(byte * &_ptData, int _DataSize)//NR24NetWork(int _Mode, byte * _ptData, int _DataSize) //uint8_t
{
  //Malloc the corret amount to communication pack:
  _ptData=(byte*)::malloc(sizeof(NR24Pack) + _DataSize);
  //The header slice must pointer to the begin of the pack:
  m_ptHeader = _ptData + _DataSize;
  //The real data slice must pointer to the end of the pack:
  m_ptData = _ptData;// + sizeof(NR24NetWorkHeader);
  
  //The communication header must pointer to the correct area on comunication pack:
  m_communicationHeader = (NR24Pack*) m_ptHeader;
  
  Mirf.csnPin = 10;
  Mirf.cePin = 9;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init(); 
  setPayLoadSize(_DataSize);
  Mirf.config();
  
  //Retry to send pack's:
  m_SendRetry = 2;
  //Set default address;
  setDefaultAddress();
  //Clear the rx buffer:
  Mirf.flushRx();
}

//--------------------------------------------------- Public functions ---------------------------------------------------
//-------------------- Get/Set functions -------------------
boolean NR24NetWork::setDefaultAddress()
{
  //Set some properties:
  setNetWorkIdent(DEFAULTMASK,DEFAULTMASK,DEFAULTMASK);
  setNodeAddress(EMPTY_ADDRESS);
  //Set password;
  setLoginPwd('1','2','3','4');
  //Set recive address:
  Mirf.setRADDR((byte *)&m_Address);
}
void NR24NetWork::setPayLoadSize(byte _DataSize)
{
  m_dataSize = _DataSize + sizeof(NR24Pack);
  Mirf.payload = m_dataSize;
}
int NR24NetWork::getPayLoadSize()
{
  return m_dataSize;
}
void NR24NetWork::setNodeAddress(int _NodeAddress)
{
  m_Address.Node = _NodeAddress;
}
void NR24NetWork::setNetWorkIdent(byte _NetWorkID_1,byte _NetWorkID_2,byte _NetWorkID_3)
{
  m_Address.NetWorkIdent[0] = _NetWorkID_1;
  m_Address.NetWorkIdent[1] = _NetWorkID_2;
  m_Address.NetWorkIdent[2] = _NetWorkID_3;
}
boolean NR24NetWork::setLoginPwd(char char1, char char2, char char3, char char4)
{
  m_login.password[0] = char1;
  m_login.password[1] = char2;
  m_login.password[2] = char3;
  m_login.password[3] = char4;
}
//-------------------- Get/Set functions -------------------

//------------------------------ write() -----------------------------
int NR24NetWork::write(int _Node)
{ 
  int m_sc = SC_FIRST_STEP;
  Timer m_tmrFaultTMO;
   
  while(true)
  {
  m_tmrFaultTMO.start(50);
  switch (m_sc)
  {
    case SC_FIRST_STEP: //Step 01 - Wait the RF24 is not sending to start the comunication.
    
    //Set transmite address:
    NR24NetCptAddress _senderAddress;
    _senderAddress.NetWorkIdent[0] = m_Address.NetWorkIdent[0]; _senderAddress.NetWorkIdent[1] = m_Address.NetWorkIdent[1]; _senderAddress.NetWorkIdent[2] = m_Address.NetWorkIdent[2];
    _senderAddress.Node = _Node;
    Mirf.setTADDR((byte *)&_senderAddress);
    
    Mirf.flushRx();
  
      if(Mirf.isSending())
      {
        Serial.print("write [Fail] - Device is already sending! ");
        return DATANOTSENT;
        break;
      }
      
      Mirf.send((byte *)&(*m_ptData));//m_ptHeader / m_ptData
      if(Mirf.isSending())
      {
        m_sc = SC_LAST_STEP;
        break;
      }
      
      if (m_tmrFaultTMO.done())
      {
        Serial.println("Write was bad!");
        return DATANOTSENT;
        break;
      }
    //Step 10 - Wait it finishes:
    case SC_LAST_STEP:
      if(!Mirf.isSending())
      {
        Serial.println("Write was good!");
        return DATASENT;
        break;
      }
      if (m_tmrFaultTMO.done())
      {
        Serial.println("Write was bad!");
        return DATANOTSENT;
        break;
      }      
  }
  
  }
}
//------------------------------ write() -----------------------------

//------------------------------ read() ------------------------------
int NR24NetWork::read()
{
  int m_sc = SC_FIRST_STEP;
  int returnCode;
  Timer m_tmrFaultTMO;
  
  
  
  while(true)
  {
  m_tmrFaultTMO.start(50);
  switch (m_sc)
  {
    //Step 01 - Wait the RF24 is not sending to start the comunication:
    case SC_FIRST_STEP:
      {
        //Set the recive address:
        Mirf.setRADDR((byte *)&m_Address);
        
        if (available() == DATANOTAVAILABLE)
        {
          return DATANOTAVAILABLE;
        }
        
        //Get the data:
        Mirf.getData((byte *)&(*m_ptData));//m_ptHeader / m_ptData
        Serial.println("Read was good!");
        Mirf.flushRx();
        return DATAREAD;
        break;
      }
  }
  
  }
}
//------------------------------ read() ------------------------------

//---------------------------- available() ---------------------------
int NR24NetWork::available()
{
  if(Mirf.isSending())
  {
    Serial.println("available() [Mensagem] - device is sending!");
    return DATANOTAVAILABLE;
  }
  if (Mirf.getStatus() == 0)
  {
    Serial.println("available() [Mensagem] - No data available - The device is power off!");
    return DATANOTAVAILABLE;
  }
  if (!Mirf.dataReady())
  {
    //Serial.println("available() [Mensagem] - No data available!");
    return DATANOTAVAILABLE;
  }
  return DATAAVAILABLE;
}
//--------------------------- available() ----------------------------

//--------------------- login() --------------------
int NR24NetWork::login(loginData _login)
{
  //Check the password:
  if( (_login.password[0] != m_communicationHeader->ReciverLogin.password[0]) || (_login.password[1] != m_communicationHeader->ReciverLogin.password[1]) || (_login.password[2] != m_communicationHeader->ReciverLogin.password[2]) || (_login.password[3] != m_communicationHeader->ReciverLogin.password[3]) )
  {
    Serial.print("Login [Fail] - Wrong password! The follow password is invalid: "); Serial.print(m_communicationHeader->ReciverLogin.password[0]); Serial.print(m_communicationHeader->ReciverLogin.password[1]); Serial.print(m_communicationHeader->ReciverLogin.password[2]); Serial.println(m_communicationHeader->ReciverLogin.password[3]);
    return WORNG_PWD;
  }
  return VALID;
}
//--------------------- login() --------------------

//------------------------------ send() -----------------------------
int NR24NetWork::send(int _Node, loginData _login, byte _CommMode, boolean _waitReturn, boolean _sendReply)
{
  //Pass the sender info:
  m_communicationHeader->SenderLogin = m_login;
  m_communicationHeader->SenderNode= m_Address.Node;
  //Pass the reciver info:
  m_communicationHeader->ReciverLogin = _login;
  //Pass the main argument, the 'commMode':
  m_communicationHeader->CommMode = _CommMode;
  m_lstCommModeSent = _CommMode;
  //Send the data to the wished node:
  write(_Node);
  if (_waitReturn == false)
  {
    return VALID;
  }
  //Now wait for a response:
  if (waitForReturn() != VALID)
  {
    return INVALID;
  }
  
  if (_sendReply == true)
  {
    //Send the last pack, without sender login because the pack doesn't need a return:
    m_communicationHeader->ReciverLogin = _login;
    write(_Node);
  }
  //Every things gonna be ok:
  Serial.println("Well sent!");
  return VALID;
}
//------------------------------ send() -----------------------------

//------------------------------ recive() -----------------------------
int NR24NetWork::recive()
{ 
  //If no data is available, so finish the function:
  if (read() != DATAREAD)
  {
    delay(10);
    return DATANOTAVAILABLE;
  }
  
  //Eache new pack recived we must reset the status:
  m_StNewDataAvailable = false;
  m_StRequestedData = false;
  
  //Do the login:
  if (login(m_login) != VALID)
  {
    return DATAREADBUTNOTVALID;
  }
  //
  switch (m_communicationHeader->CommMode)
  {
    case SndAskData_MODE:
    m_StRequestedData = true;
    return MUSTEND;
    break;
    
    case SndSetNodeAddess_MODE:
    setNetWorkIdent(m_communicationHeader->Arg1_byte,m_communicationHeader->Arg2_byte,m_communicationHeader->Arg3_byte);
    setNodeAddress(m_communicationHeader->Arg8_int);
    break;
    
    case SndSetLogin_MODE:
    setLoginPwd(m_communicationHeader->Arg4_char,m_communicationHeader->Arg5_char,m_communicationHeader->Arg6_char,m_communicationHeader->Arg7_char);
    break;
    
    case SndData_MODE:
    Serial.println("New data arrived");
    m_StNewDataAvailable = true;
    break;
    
    default:
    return INVALID;
    break;
  }
  
  if (send(m_communicationHeader->SenderNode,m_communicationHeader->SenderLogin, m_communicationHeader->CommMode, true, false) == VALID)
  {
    Serial.println("Well recived!");
    return VALID;
  }
  else
  {
    return INVALID;
  }
  
  //Now wait for a response:
  //if (waitForReturn() != VALID)
  //{
  //  return INVALID;
  //}
  
  //Every things gonna be ok:
  //Serial.println("Well recived!");
  //return VALID;
}
//------------------------------ recive() -----------------------------

//------------------------------ readWithAltValidation() -----------------------------
int NR24NetWork::waitForReturn()
{ 
  Timer m_tmrFaultTMO;
  m_communicationHeader->CommMode = -1;
  delay(30);
  while (true)
  {
    m_tmrFaultTMO.start(300);
    if (read() == DATAREAD)
    {
      if (login(m_login) == VALID)
      {
        if (m_communicationHeader->CommMode == m_lstCommModeSent)
        {
          Serial.println("waitForReturn - Recived!");
          return VALID;
        }
      }
    }
    if (m_tmrFaultTMO.done())
    {
      Serial.println("waitForReturn - TIMEOUT");
      delay(30);
      return TIMEOUT;
    }
  }
}
//------------------------------ readWithAltValidation() -----------------------------














//------------------------------ SndData() -----------------------------
boolean NR24NetWork::SndData(int _node, char _password[4])
{
  for (int i=0; i <= m_SendRetry; i++)
  {
    loginData _login;
    _login.password[0] = _password[0]; _login.password[1] = _password[1]; _login.password[2] = _password[2]; _login.password[3] = _password[3];
    
    if (send(_node,_login, SndData_MODE, true, true) == INVALID)
    {
      //Serial.println("SndData fail!");
      //return false;
    }
    else
    {
      Serial.println("SndData done!");
      return VALID;
    }
  }
  
  Serial.println("SndData fail!");
  return INVALID;
}
//------------------------------ SndData() -----------------------------

//------------------------------ SndAskData() -----------------------------
boolean NR24NetWork::SndAskData(int _node, char _password[4])
{
  for (int i=0; i <= m_SendRetry; i++)
  {
    loginData _login;
    _login.password[0] = _password[0]; _login.password[1] = _password[1]; _login.password[2] = _password[2]; _login.password[3] = _password[3];
    
    if (send(_node,_login, SndAskData_MODE, true, true) == INVALID)
    {
      //Serial.println("SndData fail!");
      //return false;
    }
    else
    {
      Serial.println("SndAskData done!");
      return VALID;
    }
  }
  
  Serial.println("SndAskData fail!");
  return INVALID;
}
//------------------------------ SndAskData() -----------------------------

//------------------------------ SndAnswerData() -----------------------------
boolean NR24NetWork::SndAnswerData()
{
  if (m_StRequestedData == false)
  {
    return INVALID;
  }
  
  m_StRequestedData = false;
  if (send(m_communicationHeader->SenderNode,m_communicationHeader->SenderLogin, m_communicationHeader->CommMode, true, false) == VALID)
  {
    Serial.println("Well recived!");
    return VALID;
  }
  else
  {
    return INVALID;
  }
}
//------------------------------ SndAnswerData() -----------------------------
