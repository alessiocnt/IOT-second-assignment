#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);     
} 
  
int Potentiometer::getValue(){
    int value = analogRead(pin);
    return map(value, 0, 1023, 0, 50);
}