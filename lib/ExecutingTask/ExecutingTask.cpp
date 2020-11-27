#include "ExecutingTask.h"

ExecutingTask::ExecutingTask(Led *led2, Sonar *sonar)
{
    this->led2 = led2;
    this->sonar = sonar;
    this->lastSpeed = 0;
    this->lastDistance = 0;
    this->tLastPrint = 0;
}

void ExecutingTask::init(int period)
{
    Task::init(period);
}

void ExecutingTask::setSamplingFrequency(int frequency)
{
    this->init(1000 / frequency);
}

void ExecutingTask::setCurrentTime(int time)
{
    currentTime = time;
}

void ExecutingTask::setTemperature(int temperature)
{
    sonar->setTemperature(temperature);
}

void ExecutingTask::setFirstDistance(float distance)
{
    lastDistance = (double)distance;
}

void ExecutingTask::tick()
{
    currentTime += myPeriod;
    if (currentTime < MAX_TIME)
    {
        double distance = (double)sonar->getDistance();
        if (distance != -1 && distance < 2)
        {
            double speed = ((distance - lastDistance) / myPeriod) * (double)1000;
            double acceleration = ((speed - lastSpeed) / myPeriod) * (double)1000;
            MsgService.sendMsg("Data:" + String(currentTime) + "," + String(distance) + "," + String(speed) + "," + String(acceleration));
            setServoMotorSpeed(speed);
            lastSpeed = speed;
            lastDistance = distance;
        }
    }
    else
    {
        this->setActive(false);
        led2->switchOff();
        endTask->setActive(true);
    }
}

void ExecutingTask::setServoMotorSpeed(double speed)
{
    int pos = map(abs(speed) * 100, 0, 200, 0, 18);
    servoMovementTask->setPosition(pos * 10);
}