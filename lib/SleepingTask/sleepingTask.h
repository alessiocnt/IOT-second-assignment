#ifndef __SLEEPINGTASK__
#define __SLEEPINGTASK__

#include <Arduino.h>
#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include "header.h"
#include "Task.h"
#include "Pir.h"


// Class that models a SleepingTask - Puts the system in sleep mode
class SleepingTask: public Task {
private:
  Pir* pir;
  void setupTask();
  static void wakeUp();
  ReadyTask* readyTask;
public:
  SleepingTask(Pir* pir, ReadyTask* readyTask);  
  void init(int period);  
  void tick();
};

#endif