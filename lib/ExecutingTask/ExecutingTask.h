#ifndef __EXECUTINGTASK__
#define __EXECUTINGTASK__

#include <Arduino.h>
#include "header.h"
#include "main.h"
#include "Task.h"
#include "Sonar.h"
#include "ServoMovementTask.h"
#include "Led.h"
#include "MsgService.h"

class ExecutingTask : public Task
{
private:
    Led *led2;
    Sonar *sonar;
    double lastDistance;
    double lastSpeed;
    int currentTime;
    int temperature;
    long tLastPrint;
    void setServoMotorSpeed(double speed);

public:
    ExecutingTask(Led *led2, Sonar *sonar);
    void init(int period);
    void setSamplingFrequency(int frequency);
    void setCurrentTime(int time);
    void setTemperature(int temperature);
    void setFirstDistance(float distance);
    void tick();
};

#endif