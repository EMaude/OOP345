#include "Product.h"
namespace w6 {
	Product::Product(std::string str)
	{
		productNum = std::stoi(str.substr(0, str.find_first_of(' ')));
		cost = std::stold(str.substr(str.find_first_of(' ') + 1, str.find(' ', str.find_first_of(' '))));
	}
	double Product::getCharge() const
	{
		return cost;
	}
	int Product::getProdNum() const
	{
		return productNum;
	}
	void Product::display(std::ostream &os) const
	{
		os.width(10);
		os << std::right << productNum;
		os.width(10);
		os.precision(2);
		os << std::right << std::fixed << cost << std::endl;
	}
}