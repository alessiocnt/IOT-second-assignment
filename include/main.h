#ifndef __MAIN_H_
#define __MAIN_H_

#include "ReadyTask.h"
#include "RunningTask.h"
#include "SleepingTask.h"
#include "ExecutingTask.h"
#include "EndTask.h"
#include "ErrorTask.h"

Task* readyTask;
Task* runningTask;
Task* sleepingTask;
Task* errorTask;
Task* executingTask;
Task* endTask;
Task* blinkTask;

#endif