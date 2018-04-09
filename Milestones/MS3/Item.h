#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "Utilities.h"

const unsigned int CODE_WIDTH = 5;

class Item {
	std::string name;          // name of the component
	std::string filler;        // name of the filler task
	std::string remover;       // name of the remover task 
	std::string description;   // detailed description
	unsigned int code;         // next shipping label
	static size_t field_width; // current maximum field width
public:
	//! Creates a item, either in a safe state or based on the string
	/*!	
	\param str The string that the item information is populated with.
	\sa Utilities::nextToken()
	*/
	Item(const std::string& = std::string());

	//! checks if Item is empty
	bool empty() const;

	//! Adds to item code
	Item& operator++(int);

	//! Gets the code value
	unsigned int getCode() const;

	//! Gets the name string
	const std::string& getName() const;

	//!gets the filler string
	const std::string& getFiller() const;

	//! gets the remover string
	const std::string& getRemover() const;

	//!  Inserts into os the name of the item and its current code.
	/*!
	\param os The output stream to write to
	\param full If the full flag is true, this function includes a complete description of the item.
	*/
	void display(std::ostream&, bool = false) const;
};

#endif // !ITEM_H
