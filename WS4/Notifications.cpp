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
			if (this->messages != nullptr)
			{
				delete[] this->messages;
				this->messages = nullptr;
			}

			this->messages = new Message[in.size];
			
			for (int i = 0; i < in.size; i++)
			{
				this->messages[i] = std::move(in.messages[i]);
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
			if(this->messages != nullptr)
			{ 
				delete[] messages;
				messages = nullptr;
			}
			this->messages = in.messages;
			this->size = in.size;
			in.messages = nullptr;
			in.size = 0;
		}
		return *this;
	}

	Notifications::~Notifications()
	{	
		size = 0; 
		if (messages != nullptr)
		{
			delete[] messages;
			messages = nullptr;
		}
	}

	void Notifications::operator+=(const Message &msg)
	{
		if (size < MAXSIZE)
		{
			Notifications *temp;
			temp = std::move(this);
			if (this->messages != nullptr)
			{
				delete[] this->messages;
				this->messages = nullptr;
				this->size = 0;
			}

			this->messages = new Message[temp->size + 1];

			for (int i = 0; i < temp->size; i++)
			{
				this->messages[i] = std::move(temp->messages[i]);
			}

			this->size = temp->size + 1;
			this->messages[this->size] = msg;
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