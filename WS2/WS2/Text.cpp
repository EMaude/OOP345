//Elliot Maude
//032830127

#include "Text.h"
using namespace std;

namespace w2
{
	Text::Text()
	{
		m_strings = nullptr; //create a new string which will be in a safe empty state
		m_size = 0;
	}
	Text::Text(const std::string &str)
	{
		if (str.empty())
		{
			*this = Text();
		}
		else
		{
			ifstream file(str);
			if (file.is_open())
			{
				string temp;
				int lcount = 0;
				while (getline(file, temp))
				{
					lcount++;
				}

				m_strings = new string[lcount];
				m_size = lcount;

				for(int i = 0; i < lcount; i++)
				{
					getline(file, m_strings[i]);
				}
			}
			else
			{
				Text();
			}
		}
	}
	Text::Text(const Text &src)
	{
		m_strings = nullptr;
		m_size = 0;
		*this = src;
	}
	Text& Text::operator=(const Text& src)
	{
		if (this != &src)
		{
			if (this->m_strings  != nullptr)
			{
				delete[] this->m_strings;
				m_size = 0;
			}
			this->m_strings = new string[src.m_size];
			this->m_size = src.m_size;
		
			for (int i = 0; i < src.m_size; i++)
			{
				this->m_strings[i] = src.m_strings[i];
			}
		}
		
		return *this;
	}
	Text::Text(Text &&src)
	{
		m_strings = nullptr;
		m_size = 0;
		*this = std::move(src);
	}
	Text& Text::operator=(Text &&src)
	{
		if (this != &src)
		{
			if (this->m_strings != nullptr)
			{
				delete[] this->m_strings;
				m_size = 0;
			}

			this->m_strings = src.m_strings;
			this->m_size = src.m_size;

			src.m_strings = nullptr;
			src.m_size = 0;
		}
		return *this;
	}
	Text::~Text()
	{
		if (m_size != 0)
		{
			delete[] m_strings;
			m_size = 0;
		}
	}
	size_t Text::size() const
	{
		/*! Returns m_size*/
		return m_size;
	}
}