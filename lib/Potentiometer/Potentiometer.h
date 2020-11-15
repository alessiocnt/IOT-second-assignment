#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__

class Potentiometer {
public: 
    Potentiometer(int pin);
    virtual int getValue() = 0;

private:
  int pin;
};

#endif
