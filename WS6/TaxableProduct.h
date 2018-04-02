#ifndef TAXABLEPRODUCT_H
#define TAXABLEPRODUCT_H
#include <iostream>
#include <fstream>

#include "Product.h"

namespace w6 {
	class TaxableProduct : public Product
	{
	private:
		enum Taxable { HST, PST };
		static double taxrate[2];
		Taxable tax;
	public:
		TaxableProduct(std::string);
		double getCharge() const;
		void display(std::ostream&) const;
	};
}
#endif // !TAXABLEPRODUCT_H