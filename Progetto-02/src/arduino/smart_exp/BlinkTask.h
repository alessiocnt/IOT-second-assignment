#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "Led.h"
#include "header.h"

#define BLINK_FOREVER -1

// Class that models a BlinkTask - led blinking
// N.B. period deve essere divisore di timeToBlink per avere un funzionamento ottimale
class BlinkTask : public Task
{
private:
    Led *led;
    int timeToBlink;
    int currentTime;
    enum
    {
        ON,
        OFF
    } lightState;
    void setupTask();

public:
    BlinkTask();
    void init(int period, Led *led, int timeToBlink);
    void tick();
};

#endif
