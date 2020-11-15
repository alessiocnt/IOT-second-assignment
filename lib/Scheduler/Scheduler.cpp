#include "Scheduler.h"
#include <TimerOne.h>

volatile bool timerFlag;

void timerHandler(void){
  timerFlag = true;
}

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timerFlag = false;
  long period = 1000l*basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
}

void Scheduler::addTask(Task* task){
  taskList.insert(task);
}

void Scheduler::removeTask(Task* task){
  taskList.erase(task);
}
  
void Scheduler::schedule(){   
  while (!timerFlag){}
  timerFlag = false;
// TODO
  for (std::list<Task>::iterator it=taskList.begin(); it != taskList.end(); it++){
    if (it->isActive() && it->updateAndCheckTime(basePeriod)){
      it->tick();
    }
  }
}
