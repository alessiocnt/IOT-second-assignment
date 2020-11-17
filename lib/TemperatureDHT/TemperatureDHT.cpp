#include "Arduino.h"
#include "TemperatureDHT.h"


TemperatureDHT::TemperatureDHT(int pin) {
    this->pin = pin;
    this->dht = new DHT(pin, DHTTYPE);
} 
  
int TemperatureDHT::getValue(){
    return dht->readTemperature();
}