#ifndef __HEADER__
#define __HEADER__

#define SLEEP_TIME 5000
#define MAX_TIME 20000
#define ERROR_TIME 2000
#define MAX_SPEED 10
#define MINFREQ 1
#define MAXFREQ 50
// MAXVEL TBD

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