#include "Product.h"
namespace w6 {

	Product::Product()
	{
	}
	Product::~Product()
	{
	}
	double Product::getCharge() const
	{
		return cost;
	}
	void Product::display(std::ostream &) const
	{
	}
	std::ostream & operator<<(std::ostream &, const iProduct &)
	{
		// TODO: insert return statement here
	}
	iProduct* readProduct(std::ifstream&) {

	}
}