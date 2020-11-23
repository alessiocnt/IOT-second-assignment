#include "EndTask.h"

EndTask::EndTask(Led* led2) {
    this->id = "EndT"; //togli
    this->led = led2;
}

void EndTask::init(int period) {
    Task::init(period);
}

void EndTask::tick() {
    if(!blinked) {
        Serial.println("A");
        blinked = true;
        blinkTask->init(this->myPeriod, led, BLINK_FOREVER);
        blinkTask->setActive(true);
    }
    if(MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "end") {
            Serial.println("B");
            blinkTask->setActive(false);
            this->setActive(false);
            readyTask->setActive(true);
            led->switchOff();
            blinked = false;
        }
    }
}
