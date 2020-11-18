#include "ExecutingTask.h"

ExecutingTask::ExecutingTask(Led* led2, ServoMotor* servoMotor, Sonar* sonar, EndTask* endTask) {
    this->led2 = led2;
    this->servoMotor = servoMotor;
    this->sonar = sonar;
    this->lastSpeed = 0;
    this->lastDistance = 0;
}

void ExecutingTask::init(int period) {
    Task::init(period);
}

void ExecutingTask::setSamplingFrequency(int frequency) {
    this->init(1000 / frequency);
}

void ExecutingTask::setCurrentTime(int time) {
    currentTime = time;
}

void ExecutingTask::setTemperature(int temperature) {
    sonar->setTemperature(temperature);
}

void ExecutingTask::tick() {
    currentTime += myPeriod;
    if(currentTime < MAX_TIME) {
        float distance = sonar->getDistance();
        float speed = (abs(distance - lastDistance) / myPeriod) * 1000;
        float acceleration = abs(speed - lastSpeed) / myPeriod;
        MsgService.sendMsg("{\"speed\":" + String(speed) + ",\"acceleration\":" + String(acceleration) + "}");
        setServoMotorSpeed(speed);
        lastSpeed = speed;
        lastDistance = distance;
    } else {
        this->setActive(false);
        led2->switchOff();
        endTask->setActive(true);
    }
}

void ExecutingTask::setServoMotorSpeed(int speed){
    servoMotor->setPosition((speed / MAX_SPEED) * 180);
}