#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "Utilities.h"
#include "Item.h"
#include "CustomerItem.h"

#ifdef _MSC_VER //modified from #ifndef cause it wasnt working
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Item;
class CustomerItem;

class CustomerOrder {
	std::string name;          // name of the customer
	std::string product;       // name of the product
	CustomerItem* order;       // address of the customer requests 
	unsigned int nOrders;      // number of requests
	static size_t field_width; // current maximum field width
public:
	/*!
	Upon instantiation, a CustomerOrder object receives a reference to an unmodifiable std::string.  This string contains the information for a single customer order.
	*/
	CustomerOrder(const std::string&);	

	/*!
	Reports Exception, should never be called
	*/
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete;

	/*!
	noexcept move constructor.
	\param src the object to move
	*/
	CustomerOrder(CustomerOrder&&) NOEXCEPT;

	/*!
	noexcept move operator.
	\param src the object to move
	*/
	CustomerOrder& operator=(CustomerOrder&&) NOEXCEPT;

	/*!
	Destructor frees the memory that holds the orders stored
	*/
	~CustomerOrder();

	/*!
	\return Returns the number of orders stored in the object
	*/
	unsigned int noOrders() const;

	/*!
	\return returns the name of the order stored at the index i. Checks bounds on i.
	*/
	const std::string& operator[](unsigned int) const;

	/*!
	searches through the customer items and fills those order for the customer items identified by item if any have not been filled.  This function increments item's code for each customer item filled.  This keeps the item code unique for each order.
	\param item The item to match to the customer items
	*/
	void fill(Item&);

	/*!
	searches through the customer items and removes the items that match
	\param item The item to match to the customer items
	*/
	void remove(Item&);

	/*!
	checks to see if the order is empty
	*/
	bool empty() const;

	/*!
	Inserts into os a description in the format of

	the name of the customer left-justified in a field of width field_width
	the name of the product left-justified in a field of width field_width
	each customer item on a separate line

	\param os The ostream object to insert  data into
	*/
	void display(std::ostream&) const;
};

#endif // CUSTOMERORDER_H