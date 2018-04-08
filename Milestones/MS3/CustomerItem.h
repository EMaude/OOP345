#ifndef CUSTOMERITEM_H
#define CUSTOMERITEM_H

#include <iostream>
#include <string>
#include "Item.h"

class Item;

class CustomerItem {
	std::string name;  // name of the requested component 
	bool filled;       // status of the request
	unsigned int code; // unique shipping label
public:
	/*!
	The constructor initializes the name identifying the item requested to the name received or to an empty state if no name was specified, initializes filled to false and initializes the item code to 0.
	\param str The constructor initializes the name identifying the item requested to the name received or to an empty state if no name was specified, initializes filled to false and initializes the item code to 0.
	*/
	CustomerItem(const std::string& = std::string());

	/*!
	returns true if the current object asks for item; false otherwise
	\param in The item to check against 
	*/
	bool asksFor(const Item&) const;

	/*! 
	Get the filled boolean
	*/
	bool isFilled() const;

	/*!
	Sets the item code for the current object to the value received and switches the status of the current object to filled
	\param in The item code to set the current object to
	*/
	void fill(const unsigned int);

	/*!
	resets the item code for the current object to 0 and resets the status of the current object to not filled
	*/
	void clear();

	/*!
	gets object name
	*/
	const std::string& getName() const;

	/*!
	inserts into os a description of the customer item as shown in the sample output listed below.  The description consists of

	the symbol + or - identifying the fill status of the item request
	the code printed on the item if filled or 0 if not filled in a field width of CODE_WIDTH padded with 0s and enclosed within brackets
	the name of the customer item
	\param os the ostream object to write to
	*/
	void display(std::ostream&) const;
};

#endif // !CUSTOMERITEM_H