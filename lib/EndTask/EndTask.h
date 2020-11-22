#ifndef __ENDTASK__
#define __ENDTASK__

#include <Arduino.h>
#include "BlinkTask.h"
#include "MsgService.h"
#include "Led.h"
#include "ReadyTask.h"

class EndTask : public Task {
private:
    BlinkTask* blinkTask;
    Led* led;
    ReadyTask* readyTask;
public:
    EndTask(BlinkTask* blinkTask, Led* led2, ReadyTask* readyTask);
    void init(int period);
    void tick();
    
};

#endif