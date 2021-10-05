#pragma once

#include <Arduino.h>
#include "Config.h"

#include "CleanWaterPump.h"

extern CleanWaterPump CWP;

class TankLevel 
{
public:
	// sensor pin
	int pinLevel1;
	int pinLevel2;


private:
	int L1;
	int L2;

public:
	TankLevel();
	~TankLevel() {};
	// initialization
	void  setup();

	// update the sensor data
	void  update();

};
