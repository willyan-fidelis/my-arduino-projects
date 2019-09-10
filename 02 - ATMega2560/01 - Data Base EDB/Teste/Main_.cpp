#define F_CPU 16000000
#define ARDUINO 105
#include "Arduino.h"
#include <EDB.h>
#include <SD.h>

File dbFile;

#define TABLE_SIZE 50000//512
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
	
	pinMode(53, OUTPUT);
	
	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		return;
	}
	
	Serial.println("initialization done.");
	
	Serial.println("Opening example.db ...");
	dbFile = SD.open("TestDB.db", FILE_WRITE);//FILE_READ
	
	
	Serial.println(db.count(), DEC);
	db.create(0, TABLE_SIZE, sizeof(logEvent));
	db.open(0);
	
	Serial.print("Record Count: "); Serial.println(db.count());
	
	Serial.println("Creating Records...");
	int recno;
	for (recno = 1; recno <= RECORDS_TO_CREATE; recno++)
	{
		logEvent.id = recno;
		logEvent.temperature = recno * 2;
		db.appendRec(EDB_REC logEvent);
		if (recno == 5)
		{
			db.deleteRec(recno);
			
		}
	}
	
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