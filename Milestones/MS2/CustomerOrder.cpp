#include "CustomerOrder.h"


size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string &str)
{
	nOrders = 0;
	order = nullptr;
	Utilities util;
	size_t pos = 0;
	bool more;

	try {
		name = util.nextToken(str, pos, more);
	}
	catch (const char* msg)
	{
		std::cerr << "no name found: " << msg << std::endl;
	}

	if (more)
	{
		try {
			product = util.nextToken(str, pos, more);
		}
		catch (const char* msg)
		{
			std::cerr << "no product name found: " << msg << std::endl;
		}
	}
	else
	{
		std::cerr << "not enough records" << std::endl;
	}

	CustomerItem temp[10];
	while (more)
	{
		std::string stemp;
		try {
			stemp = util.nextToken(str, pos, more);
		}
		catch (const char* msg)
		{
			std::cerr << "Error reading CustItem #" << nOrders << " : "<< msg << std::endl;
		}
		temp[nOrders] = CustomerItem(stemp);
		nOrders++;
	
		if (nOrders > 10) { 
			std::cerr << "Max Size reached in CustomerOrder Constructor";
			terminate(); 
		}
	}

	try {
		order = new CustomerItem[nOrders];
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Insufficient memory: CustomerOrder Constructor" << std::endl;
	}

	for (int i = 0; i < nOrders; i++)
	{
		order[i] = temp[i];
	}

	if (util.getFieldWidth() > field_width)
	{
		field_width = util.getFieldWidth();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder &src)
{
	std::cerr << "Cannot copy: " << src.name << std::endl;
}

CustomerOrder::~CustomerOrder()
{
}

unsigned int CustomerOrder::noOrders() const
{
	return nOrders;
}

const std::string & CustomerOrder::operator[](unsigned int i) const
{
	std::string temp;
	if (i < nOrders)
	{
		std::cerr << "Out of range" << std::endl;
	}
	temp = order[i].getName();
	return temp;
}

void CustomerOrder::fill(Item &item)
{
	for (int i = 0; i < nOrders; i++)
	{
		if (order[i].asksFor(item))
		{
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item &item)
{
	for (int i = 0; i < nOrders; i++)
	{
		if (order[i].asksFor(item))
		{
			order[i].clear();
		}
	}
}

bool CustomerOrder::empty() const
{
	return name.empty();
}

void CustomerOrder::display(std::ostream &os) const
{
	os.fill(' ');
	os.width(field_width);
	os << std::left << name << " : ";
	os.width(field_width);
	os << std::left << product << std::endl;

	for (int i = 0; i < nOrders; i++)
	{
		order[i].display(os);
		os << std::endl;
	}
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) NOEXCEPT
{
	nOrders = src.nOrders;
	order = new CustomerItem[nOrders];
	order = src.order;
	src.order = nullptr;

	name = src.name;
	src.name.clear();
	product = src.product;
	src.product.clear();
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) NOEXCEPT
{
	if (this != &src)
	{
		if (order != nullptr)
		{
			delete[] order;
		}
		nOrders = src.nOrders;
		order = new CustomerItem[nOrders];
		order = src.order;
		src.order = nullptr;

		name = src.name;
		src.name.clear();
		product = src.product;
		src.product.clear();
	}
	return *this;
}