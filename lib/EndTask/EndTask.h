#ifndef __ENDTASK__
#define __ENDTASK__

#include <Arduino.h>
#include "BlinkTask.h"
#include "MsgService.h"
#include "Led.h"

class EndTask : public Task {
private:
    BlinkTask* blinkTask;
    Led* led;
public:
    EndTask(BlinkTask* blinkTask, Led* led);
    void init(int period);
    void tick();
    
};

#endif