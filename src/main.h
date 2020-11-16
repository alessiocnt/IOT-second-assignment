#define SLEEP_TIME 5000
#define MAX_TIME 20000

ReadyTask* readyTask;
RunningTask* runningTask;
SleepingTask* sleepingTask;

// var globali qui per non gestire tutti gli include

// andrebbero in ReadyTask.h
virtual int currentTemperature;
virtual int samplingFrequence;