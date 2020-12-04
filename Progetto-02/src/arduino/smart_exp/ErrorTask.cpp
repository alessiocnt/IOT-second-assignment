#include "ErrorTask.h"

ErrorTask::ErrorTask(Led *led2)
{
    this->led2 = led2;
}

void ErrorTask::init(int period)
{
    Task::init(period);
    state = NOT_BLINKING;
}

void ErrorTask::tick()
{
    if (state == NOT_BLINKING)
    {
        blinkTask->init(this->myPeriod, led2, ERROR_TIME);
        blinkTask->setActive(true);
        state = BLINKING;
    }

    if (!blinkTask->isActive())
    {
        this->setActive(false);
        led2->switchOff();
        endTask->setActive(true);
        state = NOT_BLINKING;
    }
}