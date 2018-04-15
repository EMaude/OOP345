#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <iostream>
#include <vector>

#include "ItemManager.h"
#include "CustomerOrder.h"

class OrderManager : public std::vector<CustomerOrder> {
public:
	/*!
	Extracts the last object from the vector
	\return A move reference to the last vector element
	*/
	CustomerOrder&& extract();
	/*!
	checks that the items requested in the customer orders are available.
	\param im The item manager object with available items
	\param os The ostream object for error messages
	*/
	void validate(const ItemManager&, std::ostream&);
	/*!
	Displays the contents of CustomerOrders in the vector
	*/
	void display(std::ostream&) const;
};

#endif // !ORDERMANAGER_H

