
#include "CleanWaterPump.h"
#include "Debug.h"

CleanWaterPump::CleanWaterPump()
{
	pinCWP = CWO_IN;
}

void CleanWaterPump::setup() {
	pinMode(pinCWP, OUTPUT);
	Debug::println("//CW Pump is set up");
}

CleanWaterPump :: ~CleanWaterPump()
{
}

void CleanWaterPump :: update()
{
	digitalWrite(pinCWP, HIGH);   //Turn on relay
	delay(5000); // Water Filling Seconds , Amount
	digitalWrite(pinCWP, LOW);   //Turn off relay
}

