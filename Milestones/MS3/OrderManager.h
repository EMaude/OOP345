#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <iostream>
#include <vector>

#include "ItemManager.h"
#include "CustomerOrder.h"

class OrderManager : public std::vector<CustomerOrder> {
public:
	CustomerOrder&& extract();
	void validate(const ItemManager&, std::ostream&);
	void display(std::ostream&) const;
};

#endif // !ORDERMANAGER_H

