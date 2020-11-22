#include <Arduino.h>
#include <EnableInterrupt.h>
#include "main.h"
#include "Led.h"
#include "header.h"
#include "Scheduler.h"
#include "MsgService.h"

ReadyTask* readyTask;
RunningTask* runningTask;
SleepingTask* sleepingTask;
ExecutingTask* executingTask;
EndTask* endTask;
ErrorTask* errorTask;
BlinkTask* blinkTask;
EndExperimentTask* endExperimentTask;

TemperatureDHT* temperatureDHT;
Potentiometer* potentiometer;
ServoMotor* servoMotor;
Led* led1;
Led* led2;
Button* buttonStart;
Button* buttonStop;
Sonar* sonar;
Pir* pir;

Scheduler scheduler;

void createSensors() {
    temperatureDHT = new TemperatureDHT(TEMPERATURE_PIN);
    potentiometer = new Potentiometer(POT_PIN);
    servoMotor = new ServoMotor(SERVO_PIN);
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    buttonStart = new Button(BUTTON_START_PIN);
    buttonStop = new Button(BUTTON_STOP_PIN);
    sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN, temperatureDHT->getValue());
    pir = new Pir(PIR_PIN);
}

void createTasks() {
    readyTask = new ReadyTask(led1, led2, buttonStart, potentiometer, temperatureDHT, executingTask, runningTask, sleepingTask);
    runningTask = new RunningTask(buttonStop, sonar, led2, errorTask, executingTask, endTask);
    sleepingTask = new SleepingTask(pir, readyTask);
    executingTask = new ExecutingTask(led2, servoMotor, sonar, endTask);
    endTask = new EndTask(blinkTask, led2, readyTask);
    errorTask = new ErrorTask(led2, blinkTask, endTask);
    blinkTask = new BlinkTask();
    endExperimentTask = new EndExperimentTask(buttonStop, executingTask, endTask);
}

void setupTasks() {
    int MCD = 500; // TODO 
    readyTask->init(MCD);
    scheduler.addTask(readyTask);

    runningTask->init(MCD);
    scheduler.addTask(runningTask);

    sleepingTask->init(MCD);
    scheduler.addTask(sleepingTask);

    errorTask->init(MCD);
    scheduler.addTask(errorTask);
    
    scheduler.addTask(executingTask);

    endExperimentTask->init(MCD);
    scheduler.addTask(endExperimentTask);

    endTask->init(MCD);
    scheduler.addTask(endTask);

    scheduler.addTask(blinkTask);
}

void setup()
{
    createSensors();
    createTasks();
    setupTasks();
    MsgService.init();
    scheduler.init(25);
    readyTask->setActive(true);
    MsgService.sendMsg("Setting up sensors...");
    delay(5000);
    MsgService.sendMsg("ON");
}

void loop()
{
    scheduler.schedule();
    //readyTask->tick();
}
