//Elliot Maude
//032830127

#include "Utilities.h"

char Utilities::delimiter;

Utilities::Utilities()
{
    field_width = 1;
}
void Utilities::setFieldWidth(size_t fw)
{
    field_width = fw;
}
size_t Utilities::getFieldWidth() const
{
    return field_width;
}
const std::string Utilities::nextToken(const std::string& in, size_t &pos, bool& more)
{
	int i = 0;

    std::string result;
    more = false;

	result = in.substr(pos, (in.find(delimiter, pos) - pos));
    
	if(in.length() > in.find(delimiter, pos))
    {
        more = true;
    }

	pos += trim(result) + result.length() + 1;
    
	if(result.length() > field_width)
    {
        setFieldWidth(result.length());
    }

	if (result.empty())
	{
		throw "Empty String";
	}

    return result;
}

int Utilities::ftrim(std::string &str)
{
	int i = 0;
	while (!str.empty() && str.front() == ' ')
	{
		str.erase(0, 1); //remove first char
		i++;
	}
	return i;
}

int Utilities::rtrim(std::string &str)
{
	int i = 0;
	while (!str.empty() && str.back() == ' ')
	{
		str.erase(str.length() - 1, 1);
		i++;
	}
	return i;
}
int Utilities::trim(std::string &str)
{
	int i = 0;
	i += ftrim(str);
	i += rtrim(str);
	return i;
}