#include "Notifications.h"

namespace w4 {
	Notifications::Notifications()
	{
		size = 0;
		messages = nullptr;
	}

	Notifications::Notifications(const Notifications& in)
	{
		size = 0;
		messages = nullptr;

		*this = in;
	}

	Notifications& Notifications::operator=(const Notifications &in)
	{
		if (&in != this)
		{
			if (messages != nullptr)
			{
				delete[] messages;
			}
		}
	}

	Notifications::Notifications(Notifications &&)
	{
	}

	Notifications && Notifications::operator=(Notifications &&)
	{
		//TODO: insert return statement here
	}

	Notifications::~Notifications()
	{
	}

	void Notifications::operator+=(const Message & msg)
	{
		if (size < MAXSIZE)
		{
			size++;
		}
	}

	void Notifications::display(std::ostream & os) const
	{
		for (int i = 0; i < size ; i++)
		{
			messages[i].display(os);
		}
	}
}