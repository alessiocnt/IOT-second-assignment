#include "EndExperimentTask.h"

EndExperimentTask::EndExperimentTask(Button* button, ExecutingTask* executingTask, EndTask* endTask) {
    this->button = button;
    this->executingTask = executingTask;
    this->endTask= endTask;
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