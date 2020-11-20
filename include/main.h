#ifndef __MAIN_H_
#define __MAIN_H_

#include "ReadyTask.h"
#include "RunningTask.h"
#include "SleepingTask.h"
#include "ExecutingTask.h"
#include "EndTask.h"
#include "ErrorTask.h"

ReadyTask* readyTask;
RunningTask* runningTask;
SleepingTask* sleepingTask;
ErrorTask* errorTask;
ExecutingTask* executingTask;
EndTask* endTask;

#endif