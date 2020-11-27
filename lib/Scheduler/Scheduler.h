#ifndef __SCHEDULER__
#define __SCHEDULER__

#include <LinkedList.h>
#include "Task.h"

// Class that models a simple Scheduler
class Scheduler
{
    int basePeriod;
    LinkedList<Task *> taskList;

public:
    void init(int basePeriod);
    virtual void addTask(Task *task);
    virtual void schedule();
};

#endif
