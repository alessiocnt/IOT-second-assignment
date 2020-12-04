#include <Arduino.h>
#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin)
{
    this->pin = pin;
}

void ServoMotor::on()
{
    motor.attach(pin);
}

void ServoMotor::setPosition(int angle)
{
    motor.write(map(angle, 0, 180, 750, 2250));
}

void ServoMotor::off()
{
    motor.detach();
}