#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <vector>

class Task;
class ItemManager;

class TaskManager : public std::vector<Task>{
public:
	void validate(std::ostream&);
	void validate(const ItemManager&, std::ostream&);
	void display(std::ostream&) const;
};

#endif // !TASKMANAGER_H
