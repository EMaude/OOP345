#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace w4 {
	class Notifications
	{
		static const int MAXSIZE { 10 };
	private:
		Message *messages;
		int size;
	public:
		/*!Sets object to safe empty state*/
		Notifications();
		/*!Copy Constructor*/
		Notifications(const Notifications&);
		/*!Copy Assignment*/
		Notifications& operator=(const Notifications&);
		/*!Move Constructor*/
		Notifications(Notifications&&);
		/*!Move Assignment*/
		Notifications& operator=(Notifications&&);
		/*!Destructor*/
		~Notifications();
		/*!Adds message to set*/
		void operator+=(const Message& msg);
		/*!inserts message objects into os*/
		void display(std::ostream& os) const;

	};
}
#endif // !W4_NOTIFICATIONS_H