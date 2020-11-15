#ifndef __LIGHTTASK__
#define __LIGHTTASK__

#include "Task.h"
#include "Led.h"

class LightTask: public Task {
private:
  Led* led1, led2;

public:
  LightTask(Led* led1, Led* led2);  
  void init();  
  void tick();
};

#endif