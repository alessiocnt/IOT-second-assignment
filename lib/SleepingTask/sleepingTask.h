#ifndef __READYTASK__
#define __READYTASK__

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
public:
  SleepingTask(Pir* pir);  
  void init(int period);  
  void tick();
};

#endif