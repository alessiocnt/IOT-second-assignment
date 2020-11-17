#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int trigPin, int echoPin, float temperature) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    this->temperature = temperature;
    this->soundSpeed = updateSoundSpeed(temperature);
}

float Sonar::getDistance() {
    /* invio impulso */
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);
    
    /* ricevi l’eco */
    long tUS = pulseInLong(echoPin, HIGH);
    Serial.println(tUS);

    double t = tUS / 1000.0 / 1000.0 / 2;
    double d = t * soundSpeed;
    return d;
}

void Sonar::setTemperature(float tempearure) {
    this->temperature = tempearure;
    updateSoundSpeed(tempearure);
}

void Sonar::updateSoundSpeed(float temperature) {
    this->soundSpeed = 331.45 + 0.62 * temperature;
}