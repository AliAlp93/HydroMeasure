#pragma once
#include <dht11.h>  //dht11 DHT;
#include "ISensor.h"
#include "Config.h"
// dht11 DHT;

class AmbTmp : public ISensor
{
public:
  AmbTmp ();
  ~AmbTmp ();

public:
  void setup();
  void update();
  double getValue();
  
  int pinTemp;


private:
  double Amb[2];
  int chk1;
  //double AmbTemp;


};
