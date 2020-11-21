#include <Arduino.h>
#include "main.h"
#include "Led.h"
#include "header.h"
#include "Scheduler.h"

extern ReadyTask* readyTask;
extern RunningTask* runningTask;
extern SleepingTask* sleepingTask;
extern ExecutingTask* executingTask;
extern EndTask* endTask;
extern ErrorTask* errorTask;
extern BlinkTask* blinkTask;

Scheduler* scheduler = new Scheduler();


void setup()
{
    // put your setup code here, to run once:
    scheduler->addTask(readyTask);
    scheduler->addTask(runningTask);
    scheduler->addTask(sleepingTask);
    scheduler->addTask(executingTask);
    scheduler->addTask(endTask);
    scheduler->addTask(errorTask);
    scheduler->addTask(blinkTask);
}

void loop()
{
    // put your main code here, to run repeatedly:
}