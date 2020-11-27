#include <Arduino.h>
#include "Pir.h"

Pir::Pir(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Pir::getMovement()
{
    return digitalRead(pin) == HIGH;
}

int Pir::getPin()
{
    return pin;
}