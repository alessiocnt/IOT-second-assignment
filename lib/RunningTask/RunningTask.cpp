#include "RunningTask.h"

RunningTask(Button* stopBtt, Sonar* sonar){
  this->stopBtt = stopBtt;
  this->Sonar = sonar;
}
  
void RunningTask::init(int period){
  Task::init(period);
  setupTask();
}
  
void RunningTask::tick(){
  currentTime += this->myPeriod;
  if(currentTime < MAX_TIME){ // da VALUTARE SE FARE QUI O NESSLO STATO DOPO
  /**TODO
   * qunado rileva l'oggetto cambia stato e passa ad executing -> se execTask
   * ha un metodo per cui gli posso settare il current time trascorso dall'inizio de problema ok
   * così evitiamo var globale.
  */
 // if non rilevo nulla -> error
 // else -> executing
    if(sonar->getDistance() > 1){
      this->setActive(false);
      setupTask();
      errorTask->setActive(true);
      Serial.println("Error");
    }else{
      this->setActive(false);
      setupTask();
      executingTask->setActive(true);
      ////ExecutingTask->setCurrentTime(currentTime);
      ////led2->accendi() se prende la temperatura lui meglio accenderlo qui!
      Serial.println("Executing");
    }
  }else{
    this->setActive(false);
    setupTask();
    endTask->setActive(true);
    Serial.println("End");
  }
}

void ReadyTask::setupTask(){
  currentTime = 0;
}