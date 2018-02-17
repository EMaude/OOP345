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
