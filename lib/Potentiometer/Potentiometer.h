#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__
#define MIN_FREQUENCY 0
#define MAX_FREQUENCY 50

// Class that models a Potentiometer
class Potentiometer {
public: 
    Potentiometer(int pin);
    int getValue();

private:
  int pin;
};

#endif
