#pragma once
#include <Arduino.h>
#include "ISensor.h"
#include "Config.h"


class CleanWaterPump
{
public:
	CleanWaterPump();;
	~CleanWaterPump();
	// initialization
	void  setup();

	// Update to run or stop the oxygen pump
	void  update();

private:
	// points to the pointer to the array of sensors
	//ISensor** gravitySensor;
	int pinCWP;

};
