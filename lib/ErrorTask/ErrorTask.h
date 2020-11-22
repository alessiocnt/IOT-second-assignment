#ifndef __ERRORTASK__
#define __ERRORTASK__

#include <Arduino.h>
#include "header.h"
#include "Task.h"
#include "Led.h"
#include "BlinkTask.h"
#include "MsgService.h"
#include "EndTask.h"
#include "ReadyTask.h"

// Class that models an ErrorTask - led blinking
class ErrorTask: public Task {
private:
    Led* led2;
    BlinkTask* blinkTask;
    EndTask* endTask;
    bool blinked = false;
public:
    ErrorTask(Led* led2, BlinkTask* blinkTask, EndTask* endTask);  
    void init(int period);  
    void tick();
};

#endif