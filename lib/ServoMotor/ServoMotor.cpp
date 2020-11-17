#include <Arduino.h>
#include "ServoMotor.h"
ServoMotor::ServoMotor(int pin){
  this->pin = pin;  
} 

void ServoMotor::on(){
  motor.attach(pin);    
}

void ServoMotor::setPosition(int angle){
  motor.write(angle);              
}

void ServoMotor::off(){
  motor.detach();    
}