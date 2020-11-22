#ifndef __SLEEPINGTASK__
#define __SLEEPINGTASK__

#define LIBCALL_ENABLEINTERRUPT

#include <Arduino.h>
#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include "header.h"
#include "Task.h"
#include "Pir.h"
#include "MsgService.h"
#include "ReadyTask.h"

// Class that models a SleepingTask - Puts the system in sleep mode
class SleepingTask: public Task {
private:
  Pir* pir;
  static void wakeUp();
  ReadyTask* readyTask;
public:
  SleepingTask(Pir* pir, ReadyTask* readyTask);  
  void init(int period);  
  void tick();
};

#endif