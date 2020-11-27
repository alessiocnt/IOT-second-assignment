#include <Arduino.h>
#include <EnableInterrupt.h>
#include "main.h"
#include "Led.h"
#include "header.h"
#include "Scheduler.h"
#include "MsgService.h"

ReadyTask *readyTask;
RunningTask *runningTask;
SleepingTask *sleepingTask;
ExecutingTask *executingTask;
EndTask *endTask;
ErrorTask *errorTask;
BlinkTask *blinkTask;
EndExperimentTask *endExperimentTask;
ServoMovementTask *servoMovementTask;

TemperatureDHT *temperatureDHT;
Potentiometer *potentiometer;
ServoMotor *servoMotor;
Led *led1;
Led *led2;
Button *buttonStart;
Button *buttonStop;
Sonar *sonar;
Pir *pir;

Scheduler scheduler;

void createSensors()
{
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

void createTasks()
{
    readyTask = new ReadyTask(led1, led2, buttonStart, potentiometer, temperatureDHT);
    runningTask = new RunningTask(buttonStop, sonar, led2);
    sleepingTask = new SleepingTask(pir);
    executingTask = new ExecutingTask(led2, sonar);
    endTask = new EndTask(led2);
    errorTask = new ErrorTask(led2);
    blinkTask = new BlinkTask();
    endExperimentTask = new EndExperimentTask(buttonStop);
    servoMovementTask = new ServoMovementTask(servoMotor);
}

void setupTasks()
{
    int MCD = 50;
    readyTask->init(MCD);
    scheduler.addTask(readyTask);

    runningTask->init(MCD);
    scheduler.addTask(runningTask);

    sleepingTask->init(MCD);
    scheduler.addTask(sleepingTask);

    errorTask->init(2 * MCD);
    scheduler.addTask(errorTask);

    executingTask->init(MCD);
    scheduler.addTask(executingTask);

    endExperimentTask->init(MCD);
    scheduler.addTask(endExperimentTask);

    endTask->init(2 * MCD);
    scheduler.addTask(endTask);

    scheduler.addTask(blinkTask);
    blinkTask->setActive(false);

    servoMovementTask->init(MCD);
    scheduler.addTask(servoMovementTask);
}

void setup()
{
    MsgService.init();
    createSensors();
    createTasks();
    setupTasks();
    scheduler.init(SCHEDULER_FREQ);
    readyTask->setActive(true);
}

void loop()
{
    scheduler.schedule();
}
