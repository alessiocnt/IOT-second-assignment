
#ifndef __READYTASK__
#define __READYTASK__

#include "Task.h"
#include "Led.h"
#include "Button.h"
#include "Potentiometer.h"
#include "TemperatureDHT.h"
#include "LightsTask.h"
#include "StartTask.h"

// Class that models a ReadyTask - Very first stage of the system
class ReadyTask: public Task {
private:
  int currentTime;
  Button* startBtt;
  Potentiometer* pot;
  TemperatureDHT* dhtSensor;
  Led* led1, led2;
  void setupTask();

public:
  ReadyTask(Led* led1, Led* led2, Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor);  
  void init(int period);  
  void tick();
};

#endif

