#ifndef __ERRORTASK__
#define __ERRORTASK__

#include <Arduino.h>
#include "header.h"
#include "main.h"
#include "Task.h"
#include "Led.h"
#include "BlinkTask.h"
#include "MsgService.h"

// Class that models an ErrorTask - led blinking
class ErrorTask: public Task {
private:
    Led* led2;
    BlinkTask* blinkTask;
    bool blinked = false;
public:
    ErrorTask(Led* led2, BlinkTask* blinkTask);  
    void init(int period);  
    void tick();
};

#endif