#include "Message.h"

using namespace std;
namespace w4 {
	Message::Message()
	{
	}
	Message::Message(ifstream &in, char c)
	{	
		string buff;
		getline(in, buff, c);
		size_t i = 0;

		if (buff.find(' ', 1) != string::npos)
		{
			user = buff.substr(0, buff.find(' ', 1)); //Find first word and make it username

			if (buff.find('@') != string::npos) //If a @ symbol exists
			{
				i = buff.find('@');
				reply = buff.substr(i + 1, buff.find(' ', i + 1) - (i + 1));
			}
			else
			{
				i = buff.find(' ', 1);
			}

			tweet = buff.substr(i + 1, buff.find('\n', 2) - (i + 1));
		}

		if (tweet.length() < 1 || user.length() < 1)
		{
			tweet.clear();
			user.clear();
			reply.clear();
		}

	}
	Message &Message::operator=(const Message &msg)
	{
		if (this != &msg)
		{
			tweet = msg.tweet;
			user = msg.user;
			if (msg.reply.length() > 0)
			{
				reply = msg.reply;
			}
			else {
				reply.clear();
			}
		}
		return *this;
	}
	bool Message::empty() const
	{
		return tweet.empty();
	}
	void Message::display(std::ostream &os) const
	{
		if (!empty())
		{
			os << "Message\n" << "User : " << user << std::endl;

			if (!reply.empty())
			{
				os << "Reply : " << reply << std::endl;
			}

			os << "Tweet : " << tweet << std::endl;
		}
	}
}
