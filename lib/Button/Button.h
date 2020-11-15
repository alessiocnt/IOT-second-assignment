#ifndef __BUTTON__
#define __BUTTON__

class Button {
public: 
    Button(int pin);
    virtual bool isPressed() = 0;

private:
  int pin;
};

#endif
