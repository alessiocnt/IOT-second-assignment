#include "RunningTask.h"

RunningTask(Button* stopBtt){
  this->stopBtt = stopBtt;
}
  
void RunningTask::init(int period){
  Task::init(period);
  setupTask();
}
  
void RunningTask::tick(){
  currentTime += this->myPeriod;
  if(currentTime < MAX_TIME){
  /**TODO
   * qunado rileva l'oggetto cambia stato e passa ad executing -> se execTask
   * ha un metodo per cui gli posso settare il current time trascorso dall'inizio de problema ok
   * così evitiamo var globale.
  */
 // if non rilevo nulla -> error
 // else -> executing
  }
}

void ReadyTask::setupTask(){
  currentTime = 0;
}