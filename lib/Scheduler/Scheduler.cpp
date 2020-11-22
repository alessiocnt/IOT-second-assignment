#include "Scheduler.h"
//#include <TimerOne.h>
#include <MsTimer2.h>


volatile bool timerFlag;

void timerHandler(void){
  timerFlag = true;
}

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timerFlag = false;
  //long period = 1000l*basePeriod;
  //Timer1.initialize(period);
  //Timer1.attachInterrupt(timerHandler);
  MsTimer2::set(basePeriod, timerHandler); // è già in ms
  MsTimer2::start();
}

void Scheduler::addTask(Task* task){
  taskList.add(task);
}
  
void Scheduler::schedule(){   
  //BasePeriod max 20ms
  while (!timerFlag){}
  timerFlag = false;

  for (int i = 0; i < taskList.size(); i++){
    Task* it = taskList.get(i);
    if (it->isActive() && it->updateAndCheckTime(basePeriod)){
      it->tick();
    }
  }
}
