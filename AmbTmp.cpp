#include "AmbTmp.h"
#include "Config.h"
#include "Debug.h"

//dht11 DHT;
AmbTmp::AmbTmp() : pinTemp(DHTPIN2)
{
}

AmbTmp::~AmbTmp()
{
}
void AmbTmp::setup() {
  // put your setup code here, to run once:
  pinMode(pinTemp, INPUT);
  Debug::println("//AmbTemp Setup");

}

void AmbTmp::update()
{
  dht11 DHTT;

  chk1 = DHTT.read(this->pinTemp);    // READ DATA  Hum OK but Temp 3.5 --- 4 off
  Amb[0] = DHTT.humidity;
  Amb[1] = DHTT.temperature;
  //Debug::print(Amb[0]);
  //Debug::println("//Humidity Update Called in the Second");
  //Debug::print(Amb[1]);
  //Debug::println("//Temperature Update Called  in the Second");


}

double AmbTmp::getValue()
{
  return this->Amb[1];
}
