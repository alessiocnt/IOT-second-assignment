#include "LightsTask.h"

LightTask(Led* led1, Led* led2){
  this->led1 = led1;    
  this->led2 = led2;    
}
  
void LightTask::init(){
  Task::init(0);
}
  
void LightTask::tick(){
  led1->switchOn();
  led2->switchOff();
}
