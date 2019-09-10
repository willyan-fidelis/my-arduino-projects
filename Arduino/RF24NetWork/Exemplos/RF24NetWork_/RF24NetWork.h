//Header file

#ifndef _NR24NETWORK_H
#define _NR24NETWORK_H

#include <Arduino.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <Timer.h>

//Boolean/Numeric options definitions:
#define YES  true
#define NO   false
#define OK   true
#define NOK  false
#define NONE 0
#define ARG1 1
#define ARG2 2
#define ARG3 3
#define OPTION1 1
#define OPTION1 2
#define OPTION1 3
#define INVALID     0
#define VALID       1
#define TIMEOUT     2

//Broadcast/Addressing definitions:
//#define BROADCAST   -100    //Send or recive from/to any node.
#define EMPTY_ADDRESS -1      //Default address to all elements
#define DEFAULTMASK    1      //Default network mask

//Commum Step Ctrl definitions:
#define SC_FIRST_STEP       30000
#define SC_LAST_STEP        30001
#define SC_FAIL_STEP        30002
#define SC_WELLDONE_STEP    30003


//AltenticationValidation definitions:
#define WORNG_NAME            2
#define WORNG_PWD             3

//'m_CommArg' - Communication argument:
#define SndAskData_MODE              1
#define SndSetNodeAddess_MODE        2
#define SndSetLogin_MODE             3
#define SndData_MODE                 4

//read()/write()/available() returns definitions:
#define DATANOTAVAILABLE        0
#define DATAAVAILABLE           1
#define DATAREAD                1
#define DATAREADBUTNOTVALID     2
#define DATANOTSENT             0
#define DATASENT                1
#define MUSTEND                 3
#define NOANSWER                4

//ReadFrom definitions:
//#define READFROM_ALL           -1

//------------------- New ----------------------
struct NR24NetCptAddress {
  byte  NetWorkIdent[3];
  int   Node;
};

struct loginData {
  //char   name[4];
  char   password[4];
};

struct  NR24Pack {
  int    SenderNode;
  loginData  SenderLogin;
  loginData  ReciverLogin;
  byte CommMode;
  byte Arg1_byte;
  byte Arg2_byte;
  byte Arg3_byte;
  char Arg4_char;
  char Arg5_char;
  char Arg6_char;
  char Arg7_char;
  int  Arg8_int;
};
//------------------- New ----------------------

class NR24NetWork //: Nrf24l
{
public:
//Contructors:
NR24NetWork(byte * &_ptData, int _DataSize);
//Get and Set Functions:
void setNetWorkIdent(byte _NetWorkID_1,byte _NetWorkID_2,byte _NetWorkID_3);
void setNodeAddress(int _NodeAddress);
void setPayLoadSize(byte _DataSize);
int  getPayLoadSize();
boolean setLoginPwd(char char1, char char2, char char3, char char4);
//Other functions:
bool findOutAddress();                  //Find out an available address and so auto configure with it.
bool pingWith(int _NodeAddress);

//---------------------------------- User Functions ----------------------------------
//Sender func:
boolean SndSetNodeAddess(NR24NetCptAddress _Address);
boolean SndSetLogin(loginData _login);
boolean SndAskData(int _node, char _password[4]);
boolean SndData(int _node, char _password[4]);

//Reciver func:
boolean SndAnswerData();

//Others:
boolean setDefaultAddress();
//---------------------------------- User Functions ----------------------------------
//Future private functions:
int write(int _Node);
int read();
int send(int _Node, loginData _login, byte _CommMode, boolean _waitReturn, boolean _sendReply);
int recive ();
int waitForReturn();
//Auxiliar Functions:
boolean stRequestingData();
void    ReqDataRedyToGo();
int available();

private:
//Private Functions:
int AltenticationValidation(int _NodeAddress, char _password[4]);
int login(loginData _login);

//Class Members:
byte m_dataSize;
loginData m_login;
loginData m_lstSenderlogin;
NR24NetCptAddress m_Address;
int m_lstCommModeSent;
int m_SendRetry;
//Status:
//boolean m_StWaittingRequestedData;
boolean m_StRequestedData;
boolean m_StNewDataAvailable;
//Class pointer members:
byte * m_ptData;
byte * m_ptHeader;
NR24Pack * m_communicationHeader;


};
#endif
