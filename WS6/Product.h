#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <fstream>
#include <string>

#include "IProduct.h"

namespace w6 {
	class Product : public iProduct
	{
	private:
		int productNum;
		double cost;
	public:
		Product(std::string);
		double getCharge() const;
		int getProdNum() const;
		void display(std::ostream&) const;
	};
}
#endif //PRODUCT_H
