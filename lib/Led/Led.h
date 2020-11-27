#ifndef __LED__
#define __LED__

// Class that models a Led
class Led
{
public:
    Led(int pin);
    void switchOn();
    void switchOff();

private:
    int pin;
};

#endif
