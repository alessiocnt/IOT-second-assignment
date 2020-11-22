#ifndef __ENDEXPERIMENTTASK__
#define __ENDEXPERIMENTTASK__

#include <Arduino.h>
#include "header.h"
#include "Task.h"
#include "Button.h"
#include "ExecutingTask.h"
#include "EndTask.h"

class EndExperimentTask : public Task {
private:
    Button* button;
    ExecutingTask* executingTask;
    EndTask* endTask;

public:
    EndExperimentTask(Button* buttonStop, ExecutingTask* executingTask, EndTask* endTask);
    void init(int period);
    void tick();
};

#endif