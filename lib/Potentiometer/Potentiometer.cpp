#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);     
} 

// Maps the read value in a range between MIN_FREQUENCY and MAX_FREQUENCY
int Potentiometer::getValue(){
    int value = analogRead(pin);
    return map(value, 0, 1023, MIN_FREQUENCY, MAX_FREQUENCY);
}