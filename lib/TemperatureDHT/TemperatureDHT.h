#ifndef __TEMPERATUREDHT__
#define __TEMPERATUREDHT__

#include "DHT.h"
#define DHTTYPE DHT11

class TemperatureDHT {
public: 
    TemperatureDHT(int pin);
    virtual int getValue() = 0;

private:
  int pin;
};

#endif
