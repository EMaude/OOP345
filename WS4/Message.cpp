#include "Message.h"

namespace w4 {
	Message::Message()
	{
	}
	Message::Message(std::ifstream &in, char c)
	{
		getline(in, message, c);
		if (in.fail())
		{
			message.clear();
		}
	}
	Message & Message::operator=(const Message &msg)
	{
		if (this != &msg)
		{
			message = msg.message;
		}
		return *this;
	}
	Message::Message(Message &&msg)
	{
		*this = std::move(msg);
	}
	Message& Message::operator=(Message &&msg)
	{
		if (this != &msg)
		{
			message = msg.message;
			msg.message = nullptr;
		}
		return *this;
	}
	bool Message::empty() const
	{
		return message.empty();
	}
	void Message::display(std::ostream &os) const
	{
		if (!message.empty())
		{
			os << message;
		}
	}
}
