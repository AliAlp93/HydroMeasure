#pragma once
#include <dht11.h>  //dht11 DHT;
#include "ISensor.h"
#include "Config.h"
//extern dht11 DHT;

class AmbHum : public ISensor
{
public:
  AmbHum();
  ~AmbHum();

public:
  
  void setup();
  void update();
  double getValue();
  int pinHum;

private:
  double Amb[2];
	int chk;

};
