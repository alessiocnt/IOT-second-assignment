#include "StartTask.h"

StartTask(Button* startBtt, Potentiometer* pot, TemperatureDHT* dhtSensor){
  this->startBtt=startBtt;
  this->pot=pot;
  this->dhtSensor=dhtSensor;
}
  
void StartTask::init(int period){
  Task::init(period);
}
  
void StartTask::tick(){
  if(startBtt->isPressed()){
      currentTemperature = dhtSensor->getValue();
      samplingFrequence = pot->getValue();
      this->setActive(false);
  }
}
