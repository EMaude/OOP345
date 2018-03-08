#include "Notifications.h"

namespace w4 {
	Notifications::Notifications()
	{
		messages = nullptr;
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
			if (size > 0)
			{
				delete[] messages;
				messages = nullptr;
			}
			messages = new Message[in.size];
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
			messages = in.messages;
			this->size = in.size;
			in.size = 0;
			in.messages = nullptr;
		}
		return *this;
	}

	Notifications::~Notifications()
	{	
		size = 0;
		delete[] messages;
		messages = nullptr;
	}

	void Notifications::operator+=(const Message &msg)
	{
		if (size < MAXSIZE && !msg.empty())
		{
			if (size > 0)
			{
				Notifications temp = std::move(*this);
				
				delete[] messages;
				messages = nullptr;
				size = 0;

				messages = new Message[temp.size + 1];
				for (int i = 0; i < temp.size; i++)
				{
					messages[i] = temp.messages[i];
				}

				size = temp.size + 1;
				messages[size - 1] = msg;
			}
			else
			{
				messages = new Message[1];
				messages[0] = msg;
				size = 1;
			}
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