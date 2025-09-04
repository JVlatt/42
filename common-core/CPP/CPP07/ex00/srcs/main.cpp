#include "Colors.hpp"
#include "Basic.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << BRIGHT_GREEN
		<< "A = " << a << std::endl
		<< "B = " << b << std::endl
		<< "C = " << c << std::endl
		<< "D = " << d
		<< RESET << std::endl;

	std::cout << BRIGHT_CYAN
		<< "MIN MAX :"
		<< RESET << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << BRIGHT_CYAN
		<< "SWAP :"
		<< RESET << std::endl;
	::swap( a, b );
	std::cout << CYAN
		<< "Swap (A,B) : "
		<< "a = " << a
		<< " , b = " << b
		<< RESET << std::endl;
	::swap(c, d);
	std::cout << CYAN
		<< "Swap (C,D) : "
		<< "c = " << c
		<< " , d = " << d
		<< RESET << std::endl;
	return 0;
}

