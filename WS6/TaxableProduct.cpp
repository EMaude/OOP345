#include "TaxableProduct.h"
namespace w6 {
	double taxrate[] = { 0.13, 0.08 };

	TaxableProduct::TaxableProduct() : Product()
	{

	}
	TaxableProduct::~TaxableProduct()
	{
	}
	double TaxableProduct::getCharge() const
	{
		return Product::getCharge() * taxrate[tax];
	}
}