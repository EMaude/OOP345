#include "TaskManager.h"
#include <algorithm>

void TaskManager::validate(std::ostream &os)
{
	for (int i = 0; i < std::vector<Task>::size(); i++)
	{
		bool state = false;
		for (int j = 0; j < std::vector<Task>::size(); j++)
		{
			if (!state)
			{
				state = std::vector<Task>::at(i).validate(std::vector<Task>::at(j));
			}
		}
		if (!state)
		{
			os << "Validation Incomplete" << std::endl;
		}
	}
}
void TaskManager::validate(const ItemManager &im, std::ostream &os)
{
	std::for_each(im.begin(), im.end(), [&](Item a) {
		bool goodFill = std::any_of(std::vector<Task>::begin(), std::vector<Task>::end(), [&](Task b) {
			return a.getFiller() == b.getName();
		});

		bool goodRem = std::any_of(std::vector<Task>::begin(), std::vector<Task>::end(), [&](Task b) {
			return a.getRemover() == b.getName();
		});

		if (!goodFill)
		{
			os << "Task not found: " << a.getFiller() << std::endl;
		}

		if (!goodRem)
		{
			os << "Task not found: " << a.getRemover() << std::endl;
		}
	});
} 
void TaskManager::display(std::ostream &os) const
{
	std::for_each(std::vector<Task>::begin(), std::vector<Task>::end(), [&](Task a) { a.display(os); });
}