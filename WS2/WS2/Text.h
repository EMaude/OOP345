//Elliot Maude
//032830127
#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <string>
#include <iostream>
#include <fstream>

namespace w2
{
	/*! Upon instantiation, a Text object receives nothing or a reference to an unmodifiable string. The string holds the name of the text file that contains the records to be stored in an object of this class. */
	class Text
	{
	private:
		/*!Pointer to the array of dynamically allocated strings*/
		std::string* m_strings;
		
		/*!Stores the size of m_strings*/
		int m_size;

	public:
		Text();
		/*! Recives a referance to a file name, reads lines from the file and stores them in strings in the m_strings array*/
		Text(const std::string &str);
		
		/*! Copy Constructor*/
		Text(const Text& src);
		/*! Copy Operator*/
		Text& operator=(const Text& src);

		/*! Move Constructor*/
		Text(Text&& src);
		/*! Move Operator*/
		Text& operator= (Text&& src);

		/*! Deletes the m_strings memory*/
		~Text();

		/*! returns the number of records pointed to by m_strings*/
		size_t size() const;
	};
}
#endif // !W2_TEXT_H
