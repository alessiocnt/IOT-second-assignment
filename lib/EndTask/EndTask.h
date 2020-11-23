#ifndef __ENDTASK__
#define __ENDTASK__

#include <Arduino.h>
#include "main.h"
#include "MsgService.h"
#include "Led.h"

class EndTask : public Task {
private:
    Led* led;
    bool blinked = false;
public:
    EndTask(Led* led2);
    void init(int period);
    void tick();
    
};

#endif