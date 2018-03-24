#ifndef PRODUCT_H
#define PRODUCT_H

#include "IProduct.h"

namespace w6 {
	class Product : public iProduct
	{
	private:
		double cost;
	public:
		Product();
		~Product();

		double getCharge() const;
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}
#endif //PRODUCT_H
