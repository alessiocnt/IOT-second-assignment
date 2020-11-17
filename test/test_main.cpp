#include <Arduino.h>
#include <unity.h>
#include "Led.h"
#include "Button.h"
//#include "TemperatureDHT.h"
#include <DHT.h>
#include "Potentiometer.h"
#include "Pir.h"

void testLed(int pin) {
    Led* led = new Led(pin);
    Serial.print("Turning on for 1 sec led on pin: ");
    Serial.println(pin);
    led->switchOn();
    delay(1000);
    Serial.print("Turning of led on pin: ");
    Serial.println(pin);
    led->switchOff();
}

void testButton(int pin) {
    Button* btn = new Button(pin);
    Serial.print("You have two second starting now to press the button in position");
    Serial.println(pin);
    long t = millis();
    while (millis() - t < 2000)
    {
        if(btn->isPressed()) {
            Serial.println("Premuto");
        }
    }
}

void testTemp(int pin){
    /*TemperatureDHT* tmp = new TemperatureDHT(pin);
    Serial.print("Measured temperature using class: ");
    delay(2000);
    Serial.println(tmp->getValue());*/
    /*DHT dht(pin, DHTTYPE);
    Serial.print("Measured temperature directly from code: ");
    delay(2000);
    Serial.println(dht.readTemperature());*/
}

void testPot(int pin) {
    Potentiometer* pot = new Potentiometer(pin);
    Serial.print("You have ten second starting now to modify value of the potentiometer in position");
    Serial.println(pin);
    delay(2000);
    long t = millis();
    while (millis() - t < 10000)
    {
        Serial.println(pot->getValue());
    }
}

void testPir(int pin) {
    Pir* pir = new Pir(pin);
    Serial.println("You now have 5 seconds to move in front of the pir");
    delay(1000);
    long t = millis();
    while (millis() - t < 5000)
    {
        if (pir->getMovement())
        {
            Serial.println("Movement detected");
        }
        
    }
    
}


void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    UNITY_BEGIN();
}

void loop() {
    /*testLed(2);
    testLed(3);
    testButton(4);
    testButton(5);
    testTemp(7);
    testPot(A0);*/
    testPir(8);
    UNITY_END();
    return;
}