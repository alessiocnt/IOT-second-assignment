#define SLEEP_TIME 5000

ReadyTask* readyTask;
RunningTask* runningTask;
SleepingTask* sleepingTask;

// var globali qui per non gestire tutti gli include

// andrebbero in ReadyTask.h
int currentTemperature;
int samplingFrequence;