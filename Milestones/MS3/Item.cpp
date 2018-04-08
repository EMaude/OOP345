#include "Item.h"

size_t Item::field_width = 0;

Item::Item(const std::string &str)
{
	description = "no detailed description";
	code = 1;
	Utilities util;
	bool more;
	size_t pos = 0;

	if (!str.empty())
	{
		try {
			name = util.nextToken(str, pos, more);

			if (name.length() > field_width)
			{
				field_width = name.length();
			}
		}
		catch (const char* msg)
		{
			std::cerr << "No name found: " << msg << std::endl;
		}

		if (more)
		{
			try {
				filler = util.nextToken(str, pos, more);
			}
			catch (const char* msg)
			{
				std::cerr << "No filler found: " << msg << std::endl;
			}
		}
		else
		{
			std::cerr << "No enough records" << std::endl;
		}

		if (more)
		{
			try {
				remover = util.nextToken(str, pos, more);
			}
			catch (const char* msg)
			{
				std::cerr << "No remover found: " << msg << std::endl;
			}
		}
		else
		{
			std::cerr << "No enough records" << std::endl;
		}

		if (more)
		{
			std::string temp;
			try {
				temp = util.nextToken(str, pos, more);
			}
			catch (const char* msg)
			{
				std::cerr << "No code found" << std::endl;
			}
			code = stoul(temp);
		}
	}

		if (more)
		{
			try {
				description = util.nextToken(str, pos, more);
			}
			catch (const char* msg)
			{
				std::cerr << "No description found: " << msg << std::endl;
			}
		}
}

bool Item::empty() const
{
	return name.empty();
}

Item& Item::operator++(int)
{
	code++;
	return *this;
}

unsigned int Item::getCode() const
{
	return code;
}

const std::string& Item::getName() const
{
	return name;
}

const std::string & Item::getFiller() const
{
	return filler;
}

const std::string & Item::getRemover() const
{
	return remover;
}

void Item::display(std::ostream &os, bool full) const
{
	os.fill(' ');
	os.width(field_width);
	os << std::left << name;

	os << '[';
	os.width(CODE_WIDTH);
	os.fill('0');
	os << std::right << code << ']';
	os.fill(' ');
	if (full)
	{
		os << " From ";
		os.width(field_width);
		os << std::left << filler;

		os << " To ";
		os.width(field_width);
		os << std::left << remover << std::endl;

		os.width(field_width + CODE_WIDTH + 3);
		os << std::right << " : " << description;
	}
	os << std::endl;
}