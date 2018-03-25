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

	CustomerOrder(CustomerOrder&&) NOEXCEPT;
	CustomerOrder& operator=(CustomerOrder&&) NOEXCEPT;
	~CustomerOrder();
	unsigned int noOrders() const;
	const std::string& operator[](unsigned int) const;
	void fill(Item&);
	void remove(Item&);
	bool empty() const;
	void display(std::ostream&) const;
};

#endif // CUSTOMERORDER_H