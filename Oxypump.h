#pragma once
#include <Arduino.h>
#include "ISensor.h"
#include "Config.h"
//ISensor* gravitySensor[]

class Oxypump
{
public:
	Oxypump(ISensor* gravitySensor[]);;
	~Oxypump();
	// initialization
	void  setup();

	// Update to run or stop the oxygen pump
	void  update();

private:
	// points to the pointer to the array of sensors
	//ISensor** gravitySensor;
	int pinOXYp;
	ISensor** gravitySensor;

	
};
