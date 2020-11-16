#include "Arduino.h"
#include "TemperatureDHT.h"

TemperatureDHT::TemperatureDHT(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);     
    this->dht(pin, DHTTYPE);
} 
  
int TemperatureDHT::getValue(){
    return dht.readTemperature();
}