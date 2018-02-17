#ifndef W3_MESSAGE_H
#define W3_MESSAGE_H

#include <string.>
#include <iostream>
#include <fstream>

namespace w4 {

	class Message
	{
	private:
		std::string message;
	public:
		Message();
		/*!constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.
			c is the character that delimits each record*/
		Message(std::ifstream& in, char c);
		/*!returns true if object is in safe empty state*/
		bool empty() const;
		/*!displays message objects in the container*/
		void display(std::ostream&) const;
	};
}
#endif // !W3_MESSAGE_H
