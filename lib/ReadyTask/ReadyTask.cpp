#include "ReadyTask.h"

ReadyTask::ReadyTask(Led* led1, Led* led2, Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor, ExecutingTask* executingTask, RunningTask* runningTask, SleepingTask* sleepingTask){
  this->led1 = led1;    
  this->led2 = led2;
  this->startBtt=startBtt;
  this->pot=pot;
  this->dhtSensor=dhtSensor;
  this->runningTask = runningTask;
  this->executingTask = executingTask;
  this->sleepingTask = sleepingTask;
}
  
void ReadyTask::init(int period){
  Task::init(period);
  setupTask();
}
  
void ReadyTask::tick(){
  currentTime += this->myPeriod;
  if(currentTime < SLEEP_TIME){
    // Sto eseguendo il primo tick
    if(currentTime == this->myPeriod){
      led1->switchOn();
      led2->switchOff();
    }
    // Controllo la pressione del pulsante start, se premuto cambio task
    if(startBtt->isPressed()){
      executingTask->setSamplingFrequency(pot->getValue());
      executingTask->setTemperature(dhtSensor->getValue());
      this->setActive(false);
      setupTask();
      runningTask->setActive(true);
      //Serial.println("Run");
    }
  }else{
    this->setActive(false);
    setupTask();
    sleepingTask->setActive(true);
    led1->switchOff();
    MsgService.sendMsg("Sleep");
  }
}

void ReadyTask::setupTask(){
  currentTime = 0;
}

