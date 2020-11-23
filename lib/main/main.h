#ifndef __MAIN_H_
#define __MAIN_H_

#include "ReadyTask.h"
#include "RunningTask.h"
#include "SleepingTask.h"
#include "ExecutingTask.h"
#include "EndTask.h"
#include "ErrorTask.h"
#include "EndExperimentTask.h"
#include "BlinkTask.h"

extern ReadyTask* readyTask;
extern RunningTask* runningTask;
extern SleepingTask* sleepingTask;
extern ExecutingTask* executingTask;
extern EndTask* endTask;
extern ErrorTask* errorTask;
extern BlinkTask* blinkTask;
extern EndExperimentTask* endExperimentTask;
extern BlinkTask* blinkTask;

#endif