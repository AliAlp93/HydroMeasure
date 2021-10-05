

#pragma once

#include "Arduino.h"
#include "Wire.h"
#include "DFRobot_MotorStepper.h"
#include "Config.h"
//#include "GravityEc.h"
#include "GravitySensorHub.h"


class FoodPHpumps
{
public:
	// ph sensor pin


private:
	double EC;
	double PH;

public:
	FoodPHpumps();
	~FoodPHpumps() {};
	// initialization
	void  setup();

	// update the sensor data
	void  update();

	// Get the sensor data
	//double getValue();

	////set offset
	//void setOffset(float offset);
};
