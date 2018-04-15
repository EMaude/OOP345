#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <vector>

#include "Task.h"
#include "ItemManager.h"

class TaskManager : public std::vector<Task>{
public:
	/*!
	Validates all Tasks in the vector
	\param os Error Message output
	*/
	void validate(std::ostream&);
	/*!
	Validates all Tasks used by items in Item Manager are in the vector
	\param im The Item Manager
	\param os Error Message output
	*/
	void validate(const ItemManager&, std::ostream&);
	/*!
	Displays the contents of Tasks in the vector
	*/
	void display(std::ostream&) const;
};

#endif // !TASKMANAGER_H
