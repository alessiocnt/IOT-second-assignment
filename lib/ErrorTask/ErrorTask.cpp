#include "ErrorTask.h"

ErrorTask::ErrorTask(Led* led2, BlinkTask* blinkTask){
    this->led2 = led2;
    this->blinkTask = blinkTask;
}
//Perchè non dia interferenza al blinking è necessario scegliere un periodo > ERROR_TIME (tempo di blinking)
void ErrorTask::init(int period){
    Task::init(period);
}

void ErrorTask::tick(){
    blinkTask->setActive(true);
    blinkTask->init(this->myPeriod, led2, ERROR_TIME);

    if(!blinkTask->isActive()){
        this->setActive(false);
        led2->switchOff();
        endTask->setActive(true);
        Serial.println("End");
    }
}