#include "Sale.h"

namespace w6 {

	Sale::Sale(const char* filename)
	{
		std::ifstream file;

		file.open(filename);

		if (file.is_open())
		{
			while (!file.eof())
			{
				iProduct* temp = readProduct(file);
				if (temp != nullptr)
				{
					products.push_back(temp);
				}
			}
		}
	}
	Sale::~Sale()
	{
		products.clear();
	}
	void Sale::display(std::ostream & os) const
	{
		os.width(10);
		os << std::left << "Product No";
		os.width(10);
		os << std::right << "Cost";
		os << " Taxable" << std::endl;

		std::size_t i = 0;
		double total = 0;
		while (i < products.size())
		{
			products.at(i)->display(os);
			total += products.at(i)->getCharge();
			i++;
		}

		os.width(10);
		os << std::left << "Total";
		os.width(10);
		os.precision(2);
		os << std::fixed << std::right << total;
	}

}