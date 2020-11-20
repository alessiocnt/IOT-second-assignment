#ifndef __READYTASK__
#define __READYTASK__

#include "header.h"
#include "Task.h"
#include "Led.h"
#include "Button.h"
#include "Potentiometer.h"
#include "TemperatureDHT.h"
#include "RunningTask.h"
#include "ExecutingTask.h"
#include "SleepingTask.h"

// Class that models a ReadyTask - Very first stage of the system
class ReadyTask: public Task {
private:
  int currentTime;
  Button* startBtt;
  Potentiometer* pot;
  TemperatureDHT* dhtSensor;
  Led* led1;
  Led* led2;
  ExecutingTask* executingTask;
  RunningTask* runningTask;
  SleepingTask* sleepingTask;
  void setupTask();

public:
  ReadyTask(Led* led1, Led* led2, Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor, ExecutingTask* executingTask, RunningTask* runningTask, SleepingTask* sleepingTask);  
  void init(int period);  
  void tick();
};

#endif

