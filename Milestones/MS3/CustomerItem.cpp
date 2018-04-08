#include "CustomerItem.h"

CustomerItem::CustomerItem(const std::string &str)
{
	if (!str.empty())
	{
		name = str;
	}
	filled = false;
	code = 0;
}

bool CustomerItem::asksFor(const Item &in) const
{
	return name == in.getName();
}

bool CustomerItem::isFilled() const
{
	return filled;
}

void CustomerItem::fill(const unsigned int in)
{
	code = in;
	filled = true;
}

void CustomerItem::clear()
{
	code = 0;
	filled = false;
}

const std::string & CustomerItem::getName() const
{
	return name;
}

void CustomerItem::display(std::ostream &os) const
{
	if (filled == true)
	{
		os << "+";
	}
	else
	{
		os << "-";
	}
	os << " [";
	os.width(CODE_WIDTH);	
	os.fill('0');
	os << std::right << code << "] ";
	os << name;
}
