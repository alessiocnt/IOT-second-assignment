#include "BlinkTask.h"

BlinkTask::BlinkTask() {}

// Il period si traduce in tempo di blink
void BlinkTask::init(int period, Led *led, int timeToBlink)
{
    Task::init(period);
    this->led = led;
    this->timeToBlink = timeToBlink;
    setupTask();
}

void BlinkTask::tick()
{
    currentTime += this->myPeriod;
    if (timeToBlink == BLINK_FOREVER || currentTime < timeToBlink)
    {
        switch (lightState)
        {
        case OFF:
            led->switchOn();
            lightState = ON;
            break;
        case ON:
            led->switchOff();
            lightState = OFF;
            break;
        }
    }
    else
    {
        this->setActive(false);
        setupTask();
    }
}

void BlinkTask::setupTask()
{
    currentTime = 0;
    lightState = OFF;
}