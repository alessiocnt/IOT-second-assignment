#ifndef __TASK__
#define __TASK__

#include <Arduino.h>
// Class that models a Task
class Task
{
public:
    int myPeriod;

    virtual void init(int period)
    {
        myPeriod = period;
        timeElapsed = 0;
        this->active = false;
    }

    virtual void tick() = 0;

    bool updateAndCheckTime(int basePeriod)
    {
        timeElapsed += basePeriod;
        if (timeElapsed >= myPeriod)
        {
            timeElapsed = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isActive()
    {
        return active;
    }

    void setActive(bool active)
    {
        this->active = active;
    }

private:
    int timeElapsed;
    volatile bool active;
};

#endif
