#pragma once

//Serial print switch
#define DEBUG_AVR
//#define DEBUG_M0

//The maximum length of the sensor filter array
#define ARRAYLENGTH 10

//SD card update data time, 60,000 is 1 minute
#define SDUPDATEDATATIME 1000

//EC sensor is selected by default, comment this line to use TDS sensor
#define SELECTEC 

//Sensor pin settings
#define PHPIN  A6
#define ECPIN  A7
#define DOPIN  A8
#define LIGPIN A9 // raw ambient light LUX 1-6000
#define UVPIN  A13
#define TEMPPIN 26

#define DHTPIN 23     // Digital pin 23 connected to the DHT sensor
#define DHTPIN2 22
//#define PUMPPIN1 6    //peristaltic pump control pin, connect to arduino digital pin 9
//#define PUMPPIN2 7   //peristaltic pump control pin, connect to arduino digital pin 9
#define waitTime 1000 //interval time(ms) between every state
//Define Food Pump Pins
//#define FeedAen 28
//#define FeedA1 29
//#define FeedA2 30

//#define FeedBen 33
//#define FeedB1 31
//#define FeedB2 32

//Define ASIT 
//#define Asiten 34
//#define Asit1 35
//#define Asit2 36

//#define Bazen 40
//#define Baz1 38
//#define Baz2 39

//Define Tank Level Pins
#define LevelOK 15
#define LevelMin 16
//#define ORPPIN A3

#define OxyPPIN 42 // Oxygen Pump Relay Digital Write
#define CWO_IN 43 //Clean Water Pump Relay Digital Write

//Set sensor offset (calibration data)
#define PHOFFSET 15.94
#define ECKVALUE 1.0

//The maximum number of sensors
#define SENSORCOUNT 7

//The sensor corresponds to the array number, ph=0, temperature=1..., the maximum number is SENSORCOUNT-1
enum SensorNumber
{
	phSensor = 0,
	temperatureSensor,
	doSensor,
	ecSensor,
	AmHumSen,
	AmTmpSen,
	Light,
};

//Sensor Control Values
#define MinPH 7.1
#define MaxPH 7.6
#define MinEC 0.5
#define MaxEC 1.0
#define	MinDO 1.5
