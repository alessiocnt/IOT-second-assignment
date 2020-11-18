#include "ReadyTask.h"
#include "RunningTask.h"
#include "SleepingTask.h"
#include "ExecutingTask.h"
#include "EndTask.h"
#include "ErrorTask.h"

#define SLEEP_TIME 5000
#define MAX_TIME 20000
#define ERROR_TIME 2000
#define MAX_SPEED 10

ReadyTask* readyTask;
RunningTask* runningTask;
SleepingTask* sleepingTask;
ErrorTask* errorTask;
ExecutingTask* executingTask;
ErrorTask* errorTask;
EndTask* endTask;
