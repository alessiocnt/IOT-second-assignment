#include "ErrorTask.h"

ErrorTask::ErrorTask(Led* led2){
    this->led2 = led2;
}
// Il period si traduce in tempo di blink
void ErrorTask::init(int period){
    Task::init(period);
    setupTask();
}
  
void ErrorTask::tick(){
    currentTime += this->myPeriod;
    if(currentTime < ERROR_TIME) { 
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
        if(lightState == ON){
            led2->switchOff();
        }
        setupTask();
        endTask->setActive(true);
        Serial.println("End");
    }
}

void ErrorTask::setupTask() {
    currentTime = 0;
    lightState = OFF;
}