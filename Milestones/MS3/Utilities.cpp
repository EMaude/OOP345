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

	if (in.find(delimiter, pos) <= pos)
	{
		throw in + " <- No token before delimiter";
		more = false;
	}
	else
	{
		result = in.substr(pos, (in.find(delimiter, pos) - pos));

		pos += trim(result) + result.length() + 1;

		if (result.find_first_not_of(' ') != std::string::npos && !result.empty())
		{
			std::string temp = in;
			rtrim(temp);
			if (temp.length() > pos)
			{
				more = true;
			}

			if (result.length() > field_width)
			{
				setFieldWidth(result.length());
			}
		}
		else
		{
			throw "Empty String";
		}
	}
    return result;
}

int Utilities::ftrim(std::string &str)
{
	int i = 0;
	while (!str.empty() && (str.front() == ' ' || str.front() == '\t'))
	{
		str.erase(0, 1); //remove first char
		i++;
	}
	return i;
}

int Utilities::rtrim(std::string &str)
{
	int i = 0;
	while (!str.empty() && (str.back() == ' ' || str.back() == '\t'))
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