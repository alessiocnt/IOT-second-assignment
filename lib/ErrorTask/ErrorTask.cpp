#include "ErrorTask.h"

ErrorTask::ErrorTask(Led* led2){
    this->led2 = led2;
}
  
void ErrorTask::init(int period){
    Task::init(period);
    setupTask();
}
  
void ErrorTask::tick(){
    currentTime += this->myPeriod;
    if(currentTime < /*ERROR_TIME*/ 7) { 
        switch (lightState){
            case OFF:
                led2->switchOn();
                lightState = ON; 
                break;
            case ON:
                led2->switchOff();
                lightState = OFF;
                break;
        }
    } else {
        this->setActive(false);
        setupTask();
        endTask->setActive(true);
        Serial.println("End");
    }
}


// TODO
// Setup task non e' tra le funzioni definite all'interno di ErrorTask, quindi non puo' essere definita tramite 
// ErrorTask::setupTask, bisogna metterla tra le funzioni private di ErrorTask.h oppure definirla statica, 
// definendola statica non ha pero' accesso alle variabili contenute in ErrorTask
void ErrorTask::setupTask() {
    currentTime = 0;
    lightState = OFF;
}