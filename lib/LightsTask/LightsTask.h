#ifndef __LIGHTTASK__
#define __LIGHTTASK__

#include "Led.h"
#include "Task.h"

// Class that models a LightsTask - Manages the lights in the first stage of the system
class LightTask: public Task {
private:
  Led* led1, led2;

public:
  LightTask(Led* led1, Led* led2);  
  void init();  
  void tick();
};

#endif