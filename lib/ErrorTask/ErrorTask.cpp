#include "ErrorTask.h"

ErrorTask::ErrorTask(Led* led2){
    this->id = "ErrorT"; //togli
    this->led2 = led2;
}
//Perchè non dia interferenza al blinking è necessario scegliere un periodo > ERROR_TIME (tempo di blinking)
void ErrorTask::init(int period){
    Task::init(period);
}

void ErrorTask::tick(){
    if(!blinked) {
        blinked = true;
        blinkTask->init(this->myPeriod, led2, ERROR_TIME);
        blinkTask->setActive(true);
    }

    if(!blinkTask->isActive()){
        this->setActive(false);
        led2->switchOff();
        endTask->setActive(true);
        blinked = false;
    }
}