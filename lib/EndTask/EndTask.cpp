#include "EndTask.h"

EndTask::EndTask(BlinkTask* blinkTask, Led* led, ReadyTask* readyTask) {
    this->blinkTask = blinkTask;
    this->led = led;
    this->readyTask = readyTask;
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
