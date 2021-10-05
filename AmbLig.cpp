#include "AmbLig.h"
#include "Config.h"

AmbLig::AmbLig() : pinA(LIGPIN)
{
}
void AmbLig::setup() {
  // put your setup code here, to run once:
  pinMode(pinA, INPUT);
}

void AmbLig::update()
{
	

  LightRaw = analogRead(this->pinA);
  //Debug::print(LightRaw);
  //Debug::println("//LightRaw Update Called");
}


double AmbLig::getValue()
{
	/*Debug::println("//Light Get Called");*/

  return this->LightRaw;
}
