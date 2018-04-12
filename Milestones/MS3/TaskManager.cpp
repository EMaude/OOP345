#include "TaskManager.h"
#include <algorithm>

void TaskManager::validate(std::ostream &os)
{
    bool good = std::all_of(std::vector<Task>::begin(), std::vector<Task>::end(), [](auto a) {
		bool state = false;
		std::for_each(std::vector<Task>::begin(), std::vector<Task>::end(), [&](auto b) { if(a.validate(b) == true){ state = true});
		return state;
	});
}

void TaskManager::validate(const ItemManager &, std::ostream &)
{
}

void TaskManager::display(std::ostream &) const
{
}