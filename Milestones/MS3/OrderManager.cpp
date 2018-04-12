#include <algorithm>
#include "OrderManager.h"

CustomerOrder &&OrderManager::extract()
{
	auto temp = std::move(std::vector<CustomerOrder>::back());
	std::vector<CustomerOrder>::pop_back();
	return std::move(temp);
}

void OrderManager::validate(const ItemManager &im, std::ostream &os)
{
	os << "WIP" << std::endl;
}

void OrderManager::display(std::ostream &os) const
{
	std::for_each(std::vector<CustomerOrder>::begin(), std::vector<CustomerOrder>::end(), [&](auto a) { a.display(os); });
}
