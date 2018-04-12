#include "TaskManager.h"
#include <algorithm>

void TaskManager::validate(std::ostream &os)
{
    bool good = std::all_of(std::vector<Task>::begin(), std::vector<Task>::end(), [&](auto a) {
		return std::any_of(std::vector<Task>::begin(), std::vector<Task>::end(), [&](auto b) { return a.validate(b); });
	});

	if (!good)
	{
		os << "Validation Incomplete" << std::endl;
	}
}

void TaskManager::validate(const ItemManager &im, std::ostream &os)
{
	os << "WIP" << std::endl;
} 

void TaskManager::display(std::ostream &os) const
{
	std::for_each(std::vector<Task>::begin(), std::vector<Task>::end(), [&](auto a) { a.display(os); });
}