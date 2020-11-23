#include "SleepingTask.h"


SleepingTask::SleepingTask(Pir* pir)
{
    this->id = "SleepingT";
    this->pir = pir;
}

void SleepingTask::init(int period)
{
    Task::init(period);
}

void SleepingTask::tick()
{
    //Interrupt abilitati
    enableInterrupt(pir->getPin(), wakeUp, RISING);
    Serial.println("Sleep");
    delay(1000);
    //Sleep mode ON 
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
    sleep_enable();
    sleep_mode();
    //L'esecuzione riprende qui - Sleep mode OFF
    sleep_disable();
    //Interrupt disabilitati per evitare che il pir legga movimenti non voluti
    disableInterrupt(pir->getPin());
    this->setActive(false);
    readyTask->setActive(true);
    MsgService.sendMsg("Ready");
}

void SleepingTask::wakeUp()
{
    //MsgService.sendMsg("Awake");
}