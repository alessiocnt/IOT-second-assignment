#include "ReadyTask.h"
#include "RunningTask.h"
#include "SleepingTask.h"
#include "ErrorTask.h"

#define SLEEP_TIME 5000
#define MAX_TIME 20000
#define ERROR_TIME 2000

ReadyTask* readyTask;
RunningTask* runningTask;
SleepingTask* sleepingTask;
ErrorTask* errorTask;

// var globali qui per non gestire tutti gli include

// andrebbero in ReadyTask.h
external volatile int currentTemperature;
external volatile int samplingFrequence;