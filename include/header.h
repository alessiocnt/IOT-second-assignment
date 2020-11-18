#include "ReadyTask.h"
#include "RunningTask.h"
//#include "SleepingTask.h"
//#include "ExecutingTask"
#include "ErrorTask.h"

#define SLEEP_TIME 5000
#define MAX_TIME 20000
#define ERROR_TIME 2000

ReadyTask* readyTask;
RunningTask* runningTask;
//SleepingTask* sleepingTask;
//ExecutingTask* executingTask;
ErrorTask* errorTask;

// var globali qui per non gestire tutti gli include

// andrebbero in ReadyTask.h
volatile int currentTemperature;
volatile int samplingFrequence;