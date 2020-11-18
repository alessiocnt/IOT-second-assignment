#ifndef __PIR__
#define __PIR__

// Class that models a Pir
class Pir {
public:
    Pir(int pin);
    // Returns true if the pir is detecting movement
    bool getMovement();
    int getPin();

private:
    int pin;
};

#endif