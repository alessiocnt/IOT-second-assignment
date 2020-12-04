#include "EndTask.h"

EndTask::EndTask(Led *led2)
{
    this->led = led2;
}

void EndTask::init(int period)
{
    Task::init(period);
    state = NOT_BLINKING;
}

void EndTask::tick()
{
    if (state == NOT_BLINKING)
    {
        MsgService.sendMsg("State:End");
        blinkTask->init(this->myPeriod, led, BLINK_FOREVER);
        blinkTask->setActive(true);
        state = BLINKING;
    }
    if (MsgService.isMsgAvailable())
    {
        Msg *msg = MsgService.receiveMsg();
        if (msg->getContent() == "end")
        {
            blinkTask->setActive(false);
            this->setActive(false);
            readyTask->setActive(true);
            led->switchOff();
            state = NOT_BLINKING;
            servoMovementTask->init(this->myPeriod);
        }
    }
}
