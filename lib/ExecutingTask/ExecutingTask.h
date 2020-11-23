#ifndef __EXECUTINGTASK__
#define __EXECUTINGTASK__

#include <Arduino.h>
#include "header.h"
#include "main.h"
#include "Task.h"
#include "Sonar.h"
#include "ServoMotor.h"
#include "Led.h"
#include "MsgService.h"

class ExecutingTask : public Task {
private:
    Led* led2;
    ServoMotor* servoMotor;
    Sonar* sonar;
    float lastDistance;
    float lastSpeed;
    int currentTime;
    int temperature;
    void setServoMotorSpeed(int speed);

public:
    ExecutingTask(Led* led2, ServoMotor* servoMotor, Sonar* sonar);
    void init(int period);
    void setSamplingFrequency(int frequency);
    void setCurrentTime(int time);
    void setTemperature(int temperature);
    void tick();
};

#endif