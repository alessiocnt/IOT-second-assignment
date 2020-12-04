#include "RunningTask.h"

RunningTask::RunningTask(Button *stopBtt, Sonar *sonar, Led *led2)
{
    this->stopBtt = stopBtt;
    this->sonar = sonar;
    this->led2 = led2;
}

void RunningTask::init(int period)
{
    Task::init(period);
    setupTask();
}

void RunningTask::tick()
{
    currentTime += this->myPeriod;
    if (currentTime < MAX_TIME)
    {
        float objectDistance = sonar->getDistance();
        if (objectDistance > 1)
        {
            this->setActive(false);
            setupTask();
            errorTask->setActive(true);
            MsgService.sendMsg("State:Error");
        }
        else
        {
            this->setActive(false);
            setupTask();
            executingTask->setActive(true);
            executingTask->setCurrentTime(currentTime);
            executingTask->setFirstDistance(objectDistance);
            endExperimentTask->setActive(true);
            servoMovementTask->setActive(true);
            led2->switchOn();
            MsgService.sendMsg("State:Executing");
        }
    }
    else
    {
        this->setActive(false);
        setupTask();
        endTask->setActive(true);
    }
}

void RunningTask::setupTask()
{
    currentTime = 0;
}