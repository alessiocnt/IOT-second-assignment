#ifndef __READYTASK__
#define __READYTASK__

#include "Task.h"
#include "Led.h"


class ReadyTask: public Task {
private:
  Led* led1, led2;
  int timeElapsed;

public:
  ReadyTask(Led* led1, Led* led2);  
  void init(int period);  
  void tick();
};

#endif
