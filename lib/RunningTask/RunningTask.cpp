#include "RunningTask.h"

RunningTask::RunningTask(Button* stopBtt, Sonar* sonar, Led* led2){
  this->stopBtt = stopBtt;
  this->sonar = sonar;
  this->led2 = led2;
}
  
void RunningTask::init(int period){
  Task::init(period);
  setupTask();
}
  
void RunningTask::tick(){
  currentTime += this->myPeriod;
  if(currentTime < MAX_TIME){
 // if non rilevo nulla -> error
 // else -> executing
    if(sonar->getDistance() > 3){
      this->setActive(false);
      setupTask();
      errorTask->setActive(true);
      Serial.println("Error");
    }else{
      this->setActive(false);
      setupTask();
      executingTask->setActive(true);
      executingTask->setCurrentTime(currentTime);
      led2->switchOn();
      Serial.println("Executing");
    }
  }else{
    this->setActive(false);
    setupTask();
    endTask->setActive(true);
    Serial.println("End");
  }
}

void RunningTask::setupTask(){
  currentTime = 0;
}