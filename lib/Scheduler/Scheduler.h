#ifndef __SCHEDULER__
#define __SCHEDULER__

#include <LinkedList.h>
#include "Task.h"

class Scheduler {
  int basePeriod;
  LinkedList<Task*> taskList;

public:
  void init(int basePeriod);  
  virtual void addTask(Task* task);
  virtual void removeTask(int index);
  virtual void schedule();
};

#endif
