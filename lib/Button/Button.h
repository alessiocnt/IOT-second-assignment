#ifndef __BUTTON__
#define __BUTTON__

// Class that models a Button
class Button {
public: 
    Button(int pin);
    virtual bool isPressed() = 0;

private:
  int pin;
};

#endif
