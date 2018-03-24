#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 6 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>

namespace w6 {
	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

}
#endif
