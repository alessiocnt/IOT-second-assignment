#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

// Maps the read value in a range between MIN_FREQUENCY and MAX_FREQUENCY
int Potentiometer::getValue()
{
    int value = 10 * map(analogRead(pin), 0, 1023, MIN_FREQUENCY, MAX_FREQUENCY);
    return value == 30 ? 25 : value;    // aggiustamento necessario per avere un numero intero nel momento in cui si calcola il periodo.
}