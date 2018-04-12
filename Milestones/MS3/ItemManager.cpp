#include "ItemManager.h"
#include <algorithm>

void ItemManager::display(std::ostream &os, bool full) const
{
	std::for_each(std::vector<Item>::begin(), std::vector<Item>::end(), [&](auto a) { a.display(os, full); });
}
