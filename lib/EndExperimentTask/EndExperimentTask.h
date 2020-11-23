#ifndef __ENDEXPERIMENTTASK__
#define __ENDEXPERIMENTTASK__

#include <Arduino.h>
#include "header.h"
#include "main.h"
#include "Task.h"
#include "Button.h"

class EndExperimentTask : public Task {
private:
    Button* button;

public:
    EndExperimentTask(Button* buttonStop);
    void init(int period);
    void tick();
};

#endif