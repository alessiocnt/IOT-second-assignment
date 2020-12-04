#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int trigPin, int echoPin, float temperature)
{
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    this->temperature = temperature;
    updateSoundSpeed(temperature);
    this->lastDistance = -1;
}

float Sonar::getDistance()
{
    /* invio impulso */
    digitalWrite(trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin, LOW);

    /* ricevi l’eco */
    long tUS = pulseInLong(echoPin, HIGH);

    double t = tUS / 1000.0 / 1000.0 / 2;
    double d = t * soundSpeed;
    if (d - lastDistance > 5)
    {
        // Errore di lettura, scarto il valore ritornando -1
        return -1;
    }
    lastDistance = d;
    return d;
}

void Sonar::setTemperature(float tempearure)
{
    this->temperature = tempearure;
    updateSoundSpeed(tempearure);
}

void Sonar::updateSoundSpeed(float temperature)
{
    this->soundSpeed = 331.45 + 0.62 * temperature;
}