
//#define BOARD "Mega 2560"
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "GravitySensorHub.h"
#include "GravityRtc.h"
#include "GravityEc.h"
#include "GravityPh.h"
#include "GravityDo.h"
#include "OneWire.h"
#include "SdService.h"
#include "Debug.h"
//#include "FoodPump.h"
//#include "PHPump.h"
#include "FoodPHpumps.h"
#include "TankLevel.h"
#include "UVindex.h"
#include "Screen.h"
#include "Oxypump.h"
#include "CleanWaterPump.h"

CleanWaterPump CWP;


//PHPump PHP;
//FoodPump Food;

FoodPHpumps PUMPS;

// Alias clock module logic as rtc
GravityRtc rtc;
TankLevel TL;
// Alias sensor logic as sensorHub 
GravitySensorHub sensorHub;
UVindex UVind;
// Alias SD logic as sdService applied to sensors
SdService sdService = SdService(sensorHub.sensors);
Screen scr = Screen(sensorHub.sensors);
Oxypump OP = Oxypump(sensorHub.sensors);
void setup() {
	
	//Open communication at 9600 baud
	Serial.begin(9600);
	Debug::println("Serial begin");
	
	//initialize RTC module with computer time
	Debug::println("rtc.setup");
	rtc.setup();

	//Reset and initialize sensors
	Debug::println("sensorHub setup");
	sensorHub.setup();

	//Apply calibration offsets
	//Calibrate pH
	((GravityPh*)(sensorHub.sensors[phSensor]))->setOffset(PHOFFSET);
	Debug::print("pH offset: ");
	Debug::println(PHOFFSET);
	//
	//// Calibrate EC if present
	//#ifdef SELECTEC
	((GravityEc*)(sensorHub.sensors[ecSensor]))->setKValue(ECKVALUE);
	Debug::print("EC K Value: ");
	Debug::println(ECKVALUE);
	//#endif
	
	//Check for SD card and configure datafile
	Debug::println("sdService setup");
	sdService.setup();
	TL.setup();
	//PHP.setup();
	//Food.setup();
	PUMPS.setup();
	UVind.setup();
	scr.setup();
	OP.setup();
	CWP.setup();
  
}

//Create variable to track time
unsigned long updateTime = 0;

void loop() {
  
	//Update time from clock module
	rtc.update();

	//Collect sensor readings
	sensorHub.update();

	//Write data to SD card
	sdService.update();
 
	delay(5000);
	//double PH = PHH.getValue();
	//double PHH = sensorHub.getValueBySensorNumber(0);
	//Serial.print(F("ph called in Main= "));
	//Serial.println(PHH);

	//pump.update();
	//Food.update(); // Measure the EC level if it is below some values start A and B food pumps together
	//PHP.update(); // Measure the PH level if it is below some values start A and B food pumps together
	PUMPS.update();
	TL.update(); // Tank level is checked!! Clean Water Pump is started.
	UVind.update();  // This might be obsolete
	OP.update(); // This works when DO is low or EC and PH is dispensed and mixing is necessary.


		Serial.print(F("	ph()= "));
		Serial.println(sensorHub.getValueBySensorNumber(0));
		Serial.print(F("  Temp(C)= "));
		Serial.println(sensorHub.getValueBySensorNumber(1));
		Serial.print(F("  Do(mg/l)= "));
		Serial.println(sensorHub.getValueBySensorNumber(2));
		Serial.print(F("  Ec(ms/cm)= "));
		Serial.println(sensorHub.getValueBySensorNumber(3));
		Serial.print(F("  AmHumSen= "));
		Serial.println(sensorHub.getValueBySensorNumber(4));
		Serial.print(F("  AmTmpSen(C)= "));
		Serial.println(sensorHub.getValueBySensorNumber(5));
		Serial.print(F("  Light(Lux)= "));
		Serial.println(sensorHub.getValueBySensorNumber(6));
    
    Serial.println(F(" Sensor Values Printed on the screen"));
    scr.update(); // Print the values on the small screen


}
