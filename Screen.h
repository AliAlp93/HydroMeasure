#pragma once

#include "ISensor.h"
#include <LiquidCrystal.h>
#include "string.h"
#include "config.h"
#include "Arduino.h"



class Screen
{
public:
	Screen(ISensor* gravitySensor[]);
	~Screen();

	// initialization
	void  setup();

	// Update write SD card data
	void  update();

private:
	// points to the pointer to the array of sensors
	ISensor** gravitySensor;

};
