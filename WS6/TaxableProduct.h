#ifndef TAXABLEPRODUCT_H
#define TAXABLEPRODUCT_H


#include "Product.h"

namespace w6 {
	class TaxableProduct : public Product
	{
	private:
		static enum Taxable { HST, PST };
		static double taxrate[2];
		Taxable tax;
	public:
		TaxableProduct();
		~TaxableProduct();
		double getCharge() const;
	};
}
#endif // !TAXABLEPRODUCT_H