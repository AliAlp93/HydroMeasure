#pragma once
#include "Arduino.h"
#include "ISensor.h"
#include "Config.h"
#include "Debug.h"

class AmbLig : public ISensor
{
public:
  AmbLig();
  ~AmbLig();

public:

  int pinA;
  void setup();
  void update();
  double getValue();

private:
  double LightRaw;

};
