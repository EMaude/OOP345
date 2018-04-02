#ifndef W6_SALE_H
#define W6_SALE_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Product.h"
#include "TaxableProduct.h"

namespace w6 {
	class Sale
	{
	private:
		std::vector<iProduct*> products;
	public:
		Sale(const char*);
		~Sale();
		void display(std::ostream& os) const;
	};
}
#endif // !W6_SALE_H