#ifndef __SERVOTASK__
#define __SERVOTASK__

#include <Arduino.h>
#include "header.h"
#include "Task.h"
#include "ServoMotor.h"
#include "MsgService.h"

#define DELTA 10
#define INIT_DELAY 15

class ServoMovementTask : public Task
{
private:
    int position;
    int nextPosition;
    ServoMotor *servoMotor;
    void setServoPosition(int position);

public:
    ServoMovementTask(ServoMotor *servoMotor);
    void init(int period);
    void setPosition(int position);
    void tick();
};

#endif