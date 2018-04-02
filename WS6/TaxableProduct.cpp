#include "TaxableProduct.h"
namespace w6 {
	double TaxableProduct::taxrate[2] = { 0.13, 0.08 };

	TaxableProduct::TaxableProduct(std::string str) : Product(str)
	{
		if (str[str.length() - 1] == 'H')
		{
			tax = HST;
		}
		else if (str[str.length() - 1] == 'P')
		{
			tax = PST;
		}
		else
		{
			std::cerr << "Could not read tax flag" << std::endl;
		}
	}
	double TaxableProduct::getCharge() const
	{
		return Product::getCharge() * (taxrate[tax] + 1);
	}
	void TaxableProduct::display(std::ostream &os) const
	{
		std::string t = (tax == 0) ? " HST" : " PST";
		os.width(10);
		os << std::right << Product::getProdNum();
		os.width(10);
		os.precision(2);
		os << std::right << std::fixed << Product::getCharge();
		os <<  t << std::endl;
	}

	std::ostream & operator<<(std::ostream &os, const iProduct &prod)
	{
		prod.display(os);
		return os;
	}

	iProduct* readProduct(std::ifstream &file)
	{
		iProduct* newProd = nullptr;
		std::string in;
		std::getline(file, in);
		if (in.length() > 0)
		{
			int recCount = 1;
			int pos = 0;
			bool more;

			do {
				more = false;
				pos = in.find(' ', pos) + 1;
				recCount++;
				if (in.find(' ', pos) != std::string::npos)
				{
					more = true;
				}
			} while (more);

			switch (recCount)
			{
			case 2:
				newProd = new Product(in);
				break;
			case 3:
				newProd = new TaxableProduct(in);
				break;
			default:
				std::cerr << "Error reading records" << std::endl;
				break;
			}
		}
		return newProd;
	}
}