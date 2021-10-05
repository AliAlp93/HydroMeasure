#include "TankLevel.h"

TankLevel::TankLevel() :pinLevel1(LevelOK), pinLevel2(LevelMin), L1(2), L2(2)
{
}

void TankLevel::setup()
{
	Serial.println(F("Tank Level pin2 setup"));

	pinMode(pinLevel1, INPUT);
	pinMode(pinLevel2, INPUT);

}


void TankLevel::update()
{
	L1 = digitalRead(pinLevel1);
	L2 = digitalRead(pinLevel2);


	if (L1 == 1) {
		Serial.println(F("Water Level is okay"));
	}
	else if (L2==1) {
		Serial.println(F("Water Level is NOT okay:Add water!"));
		CWP.update();
	}
	else if (L2 == 0) {
		Serial.println(F("Water Level below MINIMUM,Add water!!!"));
    CWP.update();  // it should fill water in previous anyways it is just to double check
	}
	else {
		Serial.println(F("Could not read,Debug needed"));
	}


}
