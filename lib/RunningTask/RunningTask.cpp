#include "RunningTask.h"

RunningTask::RunningTask(Button* stopBtt, Sonar* sonar, Led* led2, ErrorTask* errorTask, ExecutingTask* executingTask, EndTask* endTask){
  this->stopBtt = stopBtt;
  this->sonar = sonar;
  this->led2 = led2;
  this->errorTask = errorTask;
  this->executingTask = executingTask;
  this->endTask = endTask;
}
  
void RunningTask::init(int period){
  Task::init(period);
  setupTask();
}
  
void RunningTask::tick(){
  MsgService.sendMsg("A"); // togli
  currentTime += this->myPeriod;
  if(currentTime < MAX_TIME){
    MsgService.sendMsg("B"); // togli
    if(sonar->getDistance() > 3){
      MsgService.sendMsg("C"); // togli
      this->setActive(false);
      setupTask();
      errorTask->setActive(true);
      MsgService.sendMsg("Error");
    }else{
      MsgService.sendMsg("Executing_1"); // togli
      this->setActive(false);
      setupTask();
      executingTask->setActive(true);
      executingTask->setCurrentTime(currentTime);
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