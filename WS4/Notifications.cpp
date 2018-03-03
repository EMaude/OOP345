#include "Notifications.h"

namespace w4 {
	Notifications::Notifications()
	{
		size = 0;
	}

	Notifications::Notifications(const Notifications& in)
	{
		size = 0;
		*this = in;
	}

	Notifications& Notifications::operator=(const Notifications &in)
	{
		if (&in != this)
		{
			for (int i = 0; i < in.size; i++)
			{
				this->messages[i] = in.messages[i];
			}

			this->size = in.size;
		}
		return *this;
	}

	Notifications::Notifications(Notifications &&in)
	{
		*this = std::move(in);
	}

	Notifications& Notifications::operator=(Notifications &&in)
	{
		if (this != &in)
		{
			for (int i = 0; i < in.size; i++)
			{
				this->messages[i] = in.messages[i];
			}
			this->size = in.size;
			in.size = 0;
		}
		return *this;
	}

	Notifications::~Notifications()
	{	
		size = 0; 
	}

	void Notifications::operator+=(const Message &msg)
	{
		if (size < MAXSIZE)
		{
			messages[size] = msg;
			size += 1;
		}
	}

	void Notifications::display(std::ostream & os) const
	{
		for (int i = 0; i < size; i++)
		{
			messages[i].display(os);
		}
	}
}