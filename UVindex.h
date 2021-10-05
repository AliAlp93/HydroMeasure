#pragma once

#include <Arduino.h>

#include "Config.h"

class UVindex 
{
public:
	// ph sensor pin
	int pinUV;



private:
	int index;
	int analogValue;

public:
	UVindex();
	~UVindex() {};
	// initialization
	void  setup();

	// update the sensor data
	void  update();

};
