#include "UVindex.h"

UVindex::UVindex() :pinUV(UVPIN), index(100)
{
}

void UVindex::setup()
{
	Serial.println(F("UV pin setup"));

	pinMode(pinUV, INPUT);

}


void UVindex::update()
{
	analogValue = analogRead(pinUV);

	if (analogValue < 20)
	{
		index = 0;
	}
	else
	{
		index = 0.05*analogValue - 1;
	}
	Serial.print(F("200-370nm UV int.="));
	Serial.println(index); //print the value to serial
	delay(200);

}