#include "ExecutingTask.h"

ExecutingTask::ExecutingTask(Led* led2, Sonar* sonar) {
    this->id = "ExecT"; //togli
    this->led2 = led2;
    servoMotor->on();
    delay(2000);
    servoMotor->setPosition(0);
    delay(20);
    servoMotor->setPosition(90);
    this->sonar = sonar;
    this->lastSpeed = 0;
    this->lastDistance = 0;
    this->tLastPrint = 0;
}

void ExecutingTask::init(int period) {
    Task::init(period);
}

void ExecutingTask::setSamplingFrequency(int frequency) {
    this->init(1000 / frequency);
    //this->init(1000);
}

void ExecutingTask::setCurrentTime(int time) {
    currentTime = time;
}

void ExecutingTask::setTemperature(int temperature) {
    sonar->setTemperature(temperature);
}

void ExecutingTask::setFirstDistance(float distance) {
    lastDistance = (double)distance;
}

void ExecutingTask::tick() {
    currentTime += myPeriod;
    if(currentTime < MAX_TIME) {
        double distance = (double)sonar->getDistance();
        MsgService.sendMsg(String(distance));
        if (distance != -1 && distance < 2) {
            double speed = ((distance - lastDistance) / myPeriod) * (double)1000;
            double acceleration = ((speed - lastSpeed) / myPeriod) * (double)1000;
            MsgService.sendMsg("{\"speed\":" + String(speed) + ",\"acceleration\":" + String(acceleration) + "}");
            setServoMotorSpeed(speed);
            lastSpeed = speed;
            lastDistance = distance;
        }
    } else {
        this->setActive(false);
        led2->switchOff();
        endTask->setActive(true);
        MsgService.sendMsg("End");
    }
}

void ExecutingTask::setServoMotorSpeed(double speed){
    int pos = map(abs(speed) * 100, 0, 200, 0, 18);
    //servoMotorTask->setPositon(pos * 10);
    //servoMotor->setPosition(pos);
    //Serial.println(pos);
    //int pos = abs(speed/MAX_SPEED)*180;
    // if(currentTime - tLastPrint >= 500){
    //     tLastPrint = currentTime;
    //     servoMotor->setPosition(pos);
        
    // }
}