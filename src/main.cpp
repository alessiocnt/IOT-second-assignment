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
    createSensors();
}

void loop()
{
    // put your main code here, to run repeatedly:
}

void createSensors() {
    
}