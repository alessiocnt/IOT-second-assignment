#ifndef __SCHEDULER__
#define __SCHEDULER__

#include <iostream.h>
#include <list.h>
#include "Task.h"

class Scheduler {
  int basePeriod;
  std::list<Task> taskList;

public:
  void init(int basePeriod);  
  virtual void addTask(Task* task);
  virtual void removeTask(Task* task);
  virtual void schedule();
};

#endif
