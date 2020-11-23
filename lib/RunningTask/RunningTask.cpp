#include "RunningTask.h"

RunningTask::RunningTask(Button* stopBtt, Sonar* sonar, Led* led2){
  this->id = "RunningT";
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
    float objectDistance = sonar->getDistance();
    if(objectDistance > 1){
      this->setActive(false);
      setupTask();
      errorTask->setActive(true);
      MsgService.sendMsg("Error");
    }else{
      this->setActive(false);
      setupTask();
      executingTask->setActive(true);
      executingTask->setCurrentTime(currentTime);
      executingTask->setFirstDistance(objectDistance);
      endExperimentTask->setActive(true);
      led2->switchOn();
      MsgService.sendMsg("Executing");
    }
  }else{
    this->setActive(false);
    setupTask();
    endTask->setActive(true);
    MsgService.sendMsg("End");
  }
}

void RunningTask::setupTask(){
  currentTime = 0;
}