#include "GravityEc.h"
#include "Config.h"

extern uint16_t readMedianValue(int* dataArray, uint16_t arrayLength);

GravityEc::GravityEc() :kValue(1.0), pin(ECPIN)
{
}


GravityEc::~GravityEc()
{
}

void GravityEc::setup()
{
	pinMode(pin, INPUT);
}


void GravityEc::update()
{
	int RES2 = 820.0; // needed for calibration!!
	int ECREF = 200.0; // 196.0
	int temperature = 25;
	int ecValueBuffer[ARRAYLENGTH];
	for (uint8_t i = 0; i < ARRAYLENGTH; i++)
	{
		ecValueBuffer[i] = analogRead(this->pin);
		delay(10);
	}
	averageVoltage = readMedianValue(ecValueBuffer, ARRAYLENGTH)/1024.0*5000.0;
 
	//this->ecValue = 1000 * averageVoltage / 820.0 / 196.0 /this->kValue;
	_rawEC = 1000.0* averageVoltage / RES2 / ECREF / this->kValue;
	ecValue = _rawEC / (1.0 + (0.0185*(temperature - 25.0)));  //temperature compensation

}

double GravityEc::getValue()
{
	return this->ecValue; //averageVoltage; //ecValue
}

void GravityEc::setKValue(float value)
{
	this->kValue = value;
}
