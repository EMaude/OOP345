#ifndef W3_MESSAGE_H
#define W3_MESSAGE_H
#include <iostream>
#include <fstream>
#include <string>

namespace w4 {

	class Message
	{
	private:
		std::string tweet;
		std::string user;
		std::string reply;
	public:
		Message();
		/*!constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.
			c is the character that delimits each record*/
		Message(std::ifstream& in, char c);
		/*!Copy Constructor*/
		Message& Message::operator=(const Message&);
		/*!returns true if object is in safe empty state*/
		bool empty() const;
		/*!displays message objects in the container*/
		void display(std::ostream&) const;
	};
}
#endif // !W3_MESSAGE_H
