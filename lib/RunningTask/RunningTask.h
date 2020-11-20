#ifndef __RUNNINGTASK__
#define __RUNNINGTASK__

#include <Arduino.h>
#include "header.h"
#include "Task.h"
#include "Button.h"
#include "Sonar.h"
#include "Led.h"
#include "ErrorTask.h"
#include "ExecutingTask.h"
#include "EndTask.h"

// Class that models a RunningTask - From ButtonStart to object relevation
class RunningTask: public Task {
private:
  int currentTime;
  Button* stopBtt;
  Sonar* sonar;
  Led* led2;
  ErrorTask* errorTask;
  ExecutingTask* executingTask;
  EndTask* endTask;
  void setupTask();
  
public:
  RunningTask(Button* stopBtt, Sonar* sonar, Led* led2, ErrorTask* errorTask, ExecutingTask* executingTask, EndTask* endTask);  
  void init(int period);  
  void tick();
};

#endif