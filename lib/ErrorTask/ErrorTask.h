#ifndef __ERRORTASK__
#define __ERRORTASK__

#include "Task.h"

// Class that models an ErrorTask - led blinking
class ErrorTask: public Task {
private:
    Led* led2;
    int currentTime;
    void setupTask();
    enum {ON, OFF} lightState;

public:
    ErrorTask(Led* led2);  
    void init(int period);  
    void tick();
};

#endif