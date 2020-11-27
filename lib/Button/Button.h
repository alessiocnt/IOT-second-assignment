#ifndef __BUTTON__
#define __BUTTON__

// Class that models a Button
class Button
{
public:
    Button(int pin);
    bool isPressed();

private:
    int pin;
};

#endif
