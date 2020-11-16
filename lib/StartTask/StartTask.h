#ifndef __STARTTASK__
#define __STARTTASK__

#include "Task.h"
#include "Button.h"
#include "Potentiometer.h"
#include "TemperatureDHT.h"

class StartTask: public Task {
private:
  Button* startBtt;
  Potentiometer* pot;
  TemperatureDHT* dhtSensor;

public:
  StartTask(Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor);  
  void init(int period);  
  void tick();
};

#endif