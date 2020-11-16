#ifndef __STARTTASK__
#define __STARTTASK__

#include "Task.h"
#include "Button.h"
#include "Potentiometer.h"
#include "TemperatureDHT.h"

// Class that models a StartTask - Manages the pression on a startButton and its condequences
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