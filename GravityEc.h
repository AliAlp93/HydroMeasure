#pragma once
#include "ISensor.h"
#include "Arduino.h"

class GravityEc : public ISensor
{
public:
	GravityEc();
	~GravityEc();

public:
	void setup();
	void update();
	double getValue();
	void setKValue(float value);

	int pin;
	float kValue;

private:
	float averageVoltage;
	double ecValue;
	double _rawEC;

};

