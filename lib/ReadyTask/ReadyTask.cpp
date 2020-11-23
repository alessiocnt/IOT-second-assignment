#include "ReadyTask.h"

ReadyTask::ReadyTask(Led* led1, Led* led2, Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor){
  this->id = "ReadyT";
  this->led1 = led1;    
  this->led2 = led2;
  this->startBtt=startBtt;
  this->pot=pot;
  this->dhtSensor=dhtSensor;
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
      //delay(1000);// togli
    }
    // Controllo la pressione del pulsante start, se premuto cambio task
    if(startBtt->isPressed()){
      executingTask->setSamplingFrequency(pot->getValue());
      executingTask->setTemperature(dhtSensor->getValue());
      this->setActive(false);
      runningTask->setActive(true);
      Serial.println("Run"); //togli
      setupTask();
    }
  }else{
    this->setActive(false);
    sleepingTask->setActive(true);
    Serial.print("AAAAAAAAA");
    Serial.println(sleepingTask->isActive());
    led1->switchOff();
    MsgService.sendMsg("Sleep");
    setupTask();
    Serial.print("BBBBB");
    Serial.println(sleepingTask->isActive());
  }
}

void ReadyTask::setupTask(){
  currentTime = 0;
}

