#include "Oxypump.h"
#include "Debug.h"

//ISensor * gravitySensor[]
Oxypump::Oxypump(ISensor * gravitySensor[])
{
	this->gravitySensor = gravitySensor;
	pinOXYp = OxyPPIN;
}

void Oxypump::setup() {
	pinMode(pinOXYp, OUTPUT);
	Debug::println("//Oxygen Pump is set up");
}

Oxypump :: ~Oxypump()
{
}

void Oxypump::update()
{
	if (this->gravitySensor[0]->getValue() < MinPH || this->gravitySensor[0]->getValue()>MaxPH) //the first 0 sensor is PH
	{
		Debug::print("OXY Pump PH is stirred, Value:");
		Debug::println(this->gravitySensor[0]->getValue());

		digitalWrite(pinOXYp, HIGH);   //Turn on relay
		delay(5000); //Air mixing time
		digitalWrite(pinOXYp, LOW);   //Turn off relay

	}

	if (this->gravitySensor[3]->getValue() < MinEC || this->gravitySensor[3]->getValue()> MaxEC) //the second 1 sensor is EC
	{
		Debug::print("OXY Pump EC is stirred, Value:");
		Debug::println(this->gravitySensor[3]->getValue());

		digitalWrite(pinOXYp, HIGH);   //Turn on relay
		delay(5000); //Air mixing time
		digitalWrite(pinOXYp, LOW);   //Turn off relay

	}

	if (this->gravitySensor[2]->getValue() < MinDO) // the third sensor is dissolved oxygen!!!
	{
		Debug::print("OXY Pump Oxygen Dissolved is =");
		Debug::println(this->gravitySensor[2]->getValue());

		digitalWrite(pinOXYp, HIGH);   //Turn on relay
		delay(5000);   //Air mixing time
    digitalWrite(pinOXYp, LOW);   //Turn on relay

	}
	else 
	{
	digitalWrite(pinOXYp, LOW);   //Turn off relay
	delay(5000);	 //Air mixing time
	}



 // Debug::println("//Oxygen Dissolved is =");
	//digitalWrite(pinOXYp, HIGH);   //Turn on relay
	//delay(5000);
	//digitalWrite(pinOXYp, LOW);
	//delay(5000);

}
