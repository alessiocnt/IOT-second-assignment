#ifndef __ERRORTASK__
#define __ERRORTASK__

#include <Arduino.h>
#include "Task.h"
#include "Led.h"

// Class that models an ErrorTask - led blinking
class ErrorTask: public Task {
private:
    Led* led2;
    int currentTime;
    enum {ON, OFF} lightState;
    void setupTask();

public:
    ErrorTask(Led* led2);  
    void init(int period);  
    void tick();
};

#endif