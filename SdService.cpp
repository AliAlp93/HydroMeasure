



// SD card select pin
//#if defined(__SAMD21G18A__)
#if  defined(__AVR_ATmega2560__)
const int CsPin = 53;
#else
const int CsPin = 4;
#endif

#include "SdService.h"
#include <SPI.h>
#include "Debug.h"
#include "GravityRtc.h"
#include "config.h"
#include "Debug.h"

extern GravityRtc rtc;

//Initialize variable to hold data
String dataString = "";



SdService::SdService(ISensor * gravitySensor []): chipSelect(CsPin), sdDataUpdateTime( 0 )
{
	this->gravitySensor = gravitySensor;
}


SdService :: ~ SdService ()
{
}

//********************************************************************************************
// function name: setup ()
// Function Description: Initialize the SD card
//********************************************************************************************
void SdService::setup()
{
	Debug::println("Initializing SD card...");

	//Make sure SS pin is set to output
	pinMode(SS, OUTPUT);

	//Open communication with SD card
	if (!SD.begin(chipSelect))
	{
		Debug::println("Card failed, or not present");
		// don't do anything more:
		return;
	}
	sdReady = true;
	Debug::println("card initialized.");

	// write the file header
	dataFile = SD.open("sensor.csv", FILE_WRITE);
	if (dataFile && dataFile.position() == 0) {
		Debug::println(F("Writing file header to SD"));
		// dataFile.println(F("Year,Month,Day,Hour,Minues,Second,pH,temp(C),DO(mg/l),ec(s/m),orp(mv)"));
		dataFile.println(F("date,pH,temp(C),DO(mg/l),ec(ms/cm),Hum,AmbTemp,ligth"));
		dataFile.close();
	}
}

//********************************************************************************************
// function name: update ()
// Function Description: Update data and write to SD card
//********************************************************************************************
void SdService::update()
{
	//sdReady 
	if (sdReady && millis() - sdDataUpdateTime > SDUPDATEDATATIME)
	{
		//Debug::println("Writing time to Sd card");

		//Update time from clock module
		rtc.update();
		//String YearString = "";
		//YearString = "";
		//YearString += String(rtc.year, 10);
		//Debug::print(YearString);

		//add time to dataString
		// Year Month Day Hours Minute Seconds
		dataString = "";
		dataString += String(rtc.year,10);
		dataString += "/";
		dataString += String(rtc.month, 10);
		dataString += "/";
		dataString += String(rtc.day, 10);
		dataString += "/";
		dataString += String(rtc.hour, 10);
		dataString += "/";
		dataString += String(rtc.minute, 10);
		dataString += "/";
		dataString += String(rtc.second, 10);
		dataString += ",";
		
		//Debug::print(dataString);


		// write time to SD card, write in two operations to keep write size small
		// Cannot execute SD.OPEN
		
		dataFile = SD.open("sensor.csv", FILE_WRITE);
		if (dataFile)
		{
			Debug::println(F("Writing Time to card"));
			Debug::print(dataString);

			dataFile.print(dataString);
			dataFile.close();
		}

		//Empty dataString and add sensor readings
		dataString = "";
		for (int i = 0; i < SENSORCOUNT; i++) //SENSORCOUNT
		{
			if (this->gravitySensor[i] != NULL)
			{
				int DummyV = this->gravitySensor[i]->getValue();
				connectString(this->gravitySensor[i]->getValue());
			}
			else
			{

				connectString(0);
			}
		
		}
		//Write sensor readings to SD card
		dataFile = SD.open("sensor.csv", FILE_WRITE);
		if (dataFile)
		{
			Debug::println("DATA WRITTEN AS:");
			Debug::println(dataString);
			dataFile.println(dataString);
			dataFile.close();
		}
		sdDataUpdateTime = millis();
	}
}

//********************************************************************************************
// function name: connectString ()
// Function Description: Connects the string data
//********************************************************************************************
void SdService::connectString(double value)
{
	dataString += String(value, 3);
	dataString += ",";
}
