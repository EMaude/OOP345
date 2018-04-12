#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <vector>

#include "Task.h"
#include "ItemManager.h"

class TaskManager : public std::vector<Task>{
public:
	void validate(std::ostream&);
	void validate(const ItemManager&, std::ostream&);
	void display(std::ostream&) const;
};

#endif // !TASKMANAGER_H
