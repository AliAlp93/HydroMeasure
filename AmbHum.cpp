#include "AmbHum.h"
#include "Config.h"
#include "Debug.h"

//dht11 DHT;
AmbHum::AmbHum() : pinHum(DHTPIN)
{
}

AmbHum::~AmbHum()
{
}

void AmbHum::setup() {
  // put your setup code here, to run once:
  pinMode(pinHum, INPUT);
}

void AmbHum::update()
{
	dht11 DHT;
  chk = DHT.read(this->pinHum);    // READ DATA  Hum OK but Temp 3.5 --- 4 off
  Amb[0] = DHT.humidity;
  Amb[1] = DHT.temperature;
  //Debug::print(Amb[0]);
  //Debug::println("//Humid Update Called inside humid");
  //Debug::print(Amb[1]);
  //Debug::println("//Temp. update Called inside humid");
  
}

double AmbHum::getValue()
{
  return this->Amb[0];
}
