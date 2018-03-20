//Elliot Maude
//032830127
#include "Task.h"
#include "Utilities.h"

size_t Task::field_width;

Task::Task(const std::string& in)
{
	slots = "1";
    pNextTask[0] = nullptr;
    pNextTask[1] = nullptr;

    Utilities util;

    bool more;
    size_t pos = 0;
    name = util.nextToken(in, pos, more);
    pos += name.length() + 1;
	
    if(more)
    {
			slots = util.nextToken(in, pos, more);
			pos += slots.length() + 1;
	}
	if (more)
	{
		nextTask[0] = util.nextToken(in, pos, more);
		pos += nextTask[0].length() + 1;
	}
    if(more)
    {
        nextTask[1] = util.nextToken(in, pos, more);
    }

	if (field_width < util.getFieldWidth())
	{
		field_width = util.getFieldWidth();
	}
}
bool Task::validate(const Task& task)
{
	bool result = false;

	if (task.getName() == nextTask[0])
	{
		pNextTask[0] = &task;
	}

	if (task.getName() == nextTask[1])
	{
		pNextTask[1] = &task;
	}

	if ((pNextTask[0] != nullptr || nextTask[0].empty()) && (pNextTask[1] != nullptr || nextTask[1].empty()) )
    {
        result = true;
    }
    return result;
}
const std::string& Task::getName() const
{
    return name;
}
unsigned int Task::getSlots() const
{
    return stoul(slots);
}
const Task* Task::getNextTask(Quality q) const
{
    int selection = (q == redirect)? 1 : 0;

    if(!nextTask[selection].empty() && pNextTask[selection] == nullptr)
    {
        throw "*** Validate [" + nextTask[selection] + "] @ [" + name + "] ***";
    }

    return pNextTask[selection];
}
void Task::display(std::ostream& os) const
{
	os << "Task Name    : ";
	os << std::left;
	os.width(field_width); 
	os << name;
	os << " [" << slots << "] " << std::endl;

	if (!nextTask[0].empty())
	{
		os << " Continue to : ";
		os << std::left;
		os.width(field_width); 
		os << nextTask[0];

		if (pNextTask[0] == nullptr)
		{
			os << " *** to be validated ***";
		}
		os << std::endl;
	}
    if(!nextTask[1].empty())
    {
		os << " Redirect to : ";
		os << std::left;
		os.width(field_width); 
		os << nextTask[1];

        if(pNextTask[1] == nullptr)
        {
            os << " *** to be validated ***";
        }
        os << std::endl;
    }
}

bool operator==(const Task&a, const Task&b)
{
    return a.getName() == b.getName();
}