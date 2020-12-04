#ifndef __TEMPERATUREDHT__
#define __TEMPERATUREDHT__

#include "DHT.h"
#define DHTTYPE DHT11

// Class that models a DHT11 Temperature sensor
class TemperatureDHT
{
public:
    TemperatureDHT(int pin);
    int getValue();

private:
    int pin;
    DHT *dht;
};

#endif
