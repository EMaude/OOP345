#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>

class Item;

class ItemManager : public std::vector<Item> {
public:
	/*!
	inserts into os descriptions of each item stored in the base class container. 
	\param full specifies whether a full description of the item should be inserted.

	*/
	void display(std::ostream&, bool = false) const;
};

#endif 
