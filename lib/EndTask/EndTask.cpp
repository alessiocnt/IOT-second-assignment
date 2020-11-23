#include "EndTask.h"

EndTask::EndTask(BlinkTask* blinkTask, Led* led2) {
    this->blinkTask = blinkTask;
    this->led = led;
}

void EndTask::init(int period) {
    Task::init(period);
    blinkTask->init(period, led, BLINK_FOREVER);
}

void EndTask::tick() {
    if(MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();
        if (msg->getContent() == "end") {
            blinkTask->setActive(false);
            this->setActive(false);
            readyTask->setActive(true);
        }
    }
}
