#include "Message.h"

namespace w4 {
	Message::Message()
	{
	}
	Message::Message(std::ifstream &in, char c)
	{	
		int lastread;
		std::string buff;
		getline(in, buff, c);

		buff.substr(0, buff.find_first_of(' ')).copy(user, 16); // get first word
		lastread = buff.find_first_of(' ');

		if (buff.find_first_of('@') != std::string::npos) {
			int i = buff.find_first_of('@');
			while (buff[i] != ' ')
			{
				i++;
			}

			buff.substr(buff.find_first_of('@') + 1, i).copy(reply, 16);
			lastread = i;
		}

		buff.substr(lastread + 1, buff.find_first_of('\n')).copy(tweet, 32);

	}
	Message &Message::operator=(const Message &msg)
	{
		if (this != &msg)
		{
			strcpy(tweet, msg.tweet);
			strcpy(user, msg.user);
			strcpy(reply, msg.reply);
		}
		return *this;
	}
	bool Message::empty() const
	{
		return (strlen(tweet) != 0) ? false : true;
	}
	void Message::display(std::ostream &os) const
	{
		if (empty())
		{
			os << "Message\n" << "User : " << user << std::endl;
			if (strlen(reply) != 0)
			{
				os << "Reply : " << reply << std::endl;
			}

			os << "Tweet : " << tweet << std::endl;
		}
	}
}
