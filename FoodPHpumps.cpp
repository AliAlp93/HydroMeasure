#include "FoodPHpumps.h"


extern GravitySensorHub sensorHub;

DFRobot_Motor motor1(M1, A0);
DFRobot_Motor motor2(M2, A0);
DFRobot_Motor motor3(M3, A0);
DFRobot_Motor motor4(M4, A0);

FoodPHpumps::FoodPHpumps()
{
}


void FoodPHpumps::setup()
{
	// Set all the motor control pins to outputs

	  //join i2c bus (address optional for master)
	Wire.begin();
	//Initialize D.C motor drive chip (Group1-4)
	motor1.init();
	motor2.init();
	motor3.init();
	motor4.init();

	motor1.speed(2048); //min is around 1500, max is 4096
	motor2.speed(2048);
	motor2.speed(2048);
	motor4.speed(2048);



	// Turn off motors - Initial state
	Serial.println(F("Food and PH Pumps pin setup"));

}

void FoodPHpumps::update()
{
	EC = sensorHub.getValueBySensorNumber(3); // EC value is taken
	Serial.print(F("EC called in Pump= "));
	Serial.println(EC);

	if (EC < MinEC) {
		Serial.print(F("EC<3.00,A and B work for 3s, EC="));
		Serial.println(EC);

		motor2.start(CCW);
		motor1.start(CCW);
		delay(3000); // this will be changed according to the amount that we want.
		motor2.stop();
		motor1.stop();
	}

	else {
		
		Serial.println(F("MinEC< ACTUAL EC < MaxEC"));

		//Maybe add a water pump function with a class!!! in case of evaporation.

	}

	PH = sensorHub.getValueBySensorNumber(0); // PH value is taken


	if (PH < MinPH) {
		Serial.print(F("PH<7.0 ,Baz  work for 3s, PH="));
		Serial.println(PH);
		//printSomeInfo();

		motor4.start(CCW);
		delay(3000);

		motor4.stop();

	}
	else if (PH > MaxPH) {
		Serial.print(F("PH>7.7, ASIT works for 3s, PH="));
		Serial.println(PH);
		//printSomeInfo();
		motor3.start(CCW);
		delay(3000);
		motor3.stop();
	}
	else {

	}
}
