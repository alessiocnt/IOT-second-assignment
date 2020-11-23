#include "EndExperimentTask.h"

EndExperimentTask::EndExperimentTask(Button* buttonStop) {
    this->id = "EndExperimentT"; //togli
    this->button = buttonStop;
}

void EndExperimentTask::init(int period) {
    Task::init(period);
}

void EndExperimentTask::tick() {
    if(button->isPressed()) {
        executingTask->setActive(false);
        this->setActive(false);
        endTask->setActive(true);
    }
}