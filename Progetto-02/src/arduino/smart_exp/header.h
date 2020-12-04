#ifndef __HEADER__
#define __HEADER__

#define SLEEP_TIME 5000
#define MAX_TIME 20000
#define ERROR_TIME 2000
#define MAX_SPEED 0.15
#define SCHEDULER_FREQ 10
#define TASK_BASE_PERIOD 50

#define TEMPERATURE_PIN 7
#define POT_PIN A0
#define SERVO_PIN 6
#define LED1_PIN 2
#define LED2_PIN 3
#define BUTTON_START_PIN 5
#define BUTTON_STOP_PIN 4
#define PIR_PIN 8
#define SONAR_TRIG_PIN 13
#define SONAR_ECHO_PIN 12

// Necessaria forward declaration in quanto le inclusioni di alcuni task devono essere ad anello
class EndTask;
class ReadyTask;
class SleepingTask;
class BlinkTask;
class EndExperimentTask;
class ErrorTask;
class ExecutingTask;
class RunningTask;

#endif