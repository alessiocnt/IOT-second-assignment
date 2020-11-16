#include "ReadyTask.h"

ReadyTask(Led* led1, Led* led2, Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor){
  Task* lights = new LightsTask(led1, led2);
  lights->init();
  lights->setActive(true);
  Task* start = new StartTask(startBtt, pot, dhtSensor);
  start->init();
  start->setActive(true);
}
  
void ReadyTask::init(int period){
  Task::init(period);
  timeElapsed = 0;
}
  
void ReadyTask::tick(){
  timeElapsed += this->myPeriod;
  if(timeElapsed < SLEEP_TIME){
    if(lights->isActive()){
      lights->tick();
      lights->setActive(false);
    }
    if(start->isActive()){
      start->tick();
    } else{
      this->setActive(false);
      runningTask->setActive(true);
      Serial.println("Run");
    }
  } else{
      this->setActive(false);
      sleepingTask->setActive(true);
      Serial.println("Sleep");
    }
}

