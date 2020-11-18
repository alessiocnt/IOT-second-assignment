#ifndef __RUNNINGTASK__
#define __RUNNINGTASK__

#include <Arduino.h>
#include "Task.h"
#include "Button.h"
#include "Sonar.h"

// Class that models a RunningTask - From ButtonStart to object relevation
class RunningTask: public Task {
private:
  int currentTime;
  Button* stopBtt;
  Sonar* sonar;
  void setupTask();
  
public:
  RunningTask(Button* stopBtt, Sonar* sonar);  
  void init(int period);  
  void tick();
};

#endif