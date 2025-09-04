#include "Base.hpp"
#include <iostream>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base* obj = generate();

	std::cout << "Identifying via pointer: ";
	identify(obj);

	std::cout << "Identifying via reference: ";
	identify(*obj);

	delete obj;
	return 0;
}
