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
}

void createTasks() {
    int MCD = 50; // TODO select right MCD
    readyTask = new ReadyTask(led1, led2, buttonStart, potentiometer, temperatureDHT, executingTask, runningTask, sleepingTask);
}

void setup()
{
    createSensors();
    createTasks();
}

void loop()
{
    // put your main code here, to run repeatedly:
}
