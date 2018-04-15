#include <algorithm>
#include "OrderManager.h"

CustomerOrder &&OrderManager::extract()
{
	return std::move(std::vector<CustomerOrder>::back());
}

void OrderManager::validate(const ItemManager &im, std::ostream &os)
{
	for (int j = 0; j < std::vector<CustomerOrder>::size(); j++)
	{
		for (int i = 0; i < std::vector<CustomerOrder>::at(j).noOrders(); i++)
		{
			bool bad = std::none_of(im.begin(), im.end(), [&](auto b) {
				return std::vector<CustomerOrder>::at(j)[i] == b.getName();
			});

			if (bad)
			{
				os << std::vector<CustomerOrder>::at(j)[i] << " is Unavailable" << std::endl;
			}
		}
	};
}

void OrderManager::display(std::ostream &os) const
{
	for (int i = 0; i < std::vector<CustomerOrder>::size(); i++) {
		std::vector<CustomerOrder>::at(i).display(os);
	}
}
