#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__
#define MIN_FREQUENCY 1
#define MAX_FREQUENCY 10

// Class that models a Potentiometer
class Potentiometer {
public: 
    Potentiometer(int pin);
    int getValue();

private:
  int pin;
};

#endif
