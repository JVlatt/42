#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	std::srand(std::time(NULL));
	int r = std::rand() % 3;

	switch (r)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "It is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It is C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "It is A" << std::endl;
	} catch (...) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "It is B" << std::endl;
		} catch (...) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "It is C" << std::endl;
			} catch (...) {
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}
