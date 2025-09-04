#include <iostream>
#include "Colors.hpp"
#include "Fixed.hpp"

int main()
{
	Fixed a(5.05f);
	Fixed b(2);
	Fixed c(10.0f);
	Fixed d(20);
	Fixed e(5.0f);
	Fixed f(10.0f);

	std::cout << GREEN << "a = " << RESET << a << std::endl;
	std::cout << GREEN << "b = " << RESET << b << std::endl;
	std::cout << GREEN << "c = " << RESET << c << std::endl;
	std::cout << GREEN << "d = " << RESET << d << std::endl;
	std::cout << GREEN << "e = " << RESET << e << std::endl;
	std::cout << GREEN << "f = " << RESET << f << std::endl;

	Fixed sum = a + b;
	Fixed diff = a - c;
	Fixed prod = a * b;
	Fixed quot = a / b;

	std::cout << BRIGHT_YELLOW << "a + b = " << RESET << sum << std::endl;
	std::cout << BRIGHT_YELLOW << "a - c = " << RESET << diff << std::endl;
	std::cout << BRIGHT_YELLOW << "a * b = " << RESET << prod << std::endl;
	std::cout << BRIGHT_YELLOW << "a / b = " << RESET << quot << std::endl;

	std::cout << BLUE << "a > b: " << RESET << (a > b) << std::endl;
	std::cout << BLUE << "a < b: " << RESET << (a < b) << std::endl;
	std::cout << BLUE << "a >= b: " << RESET << (a >= b) << std::endl;
	std::cout << BLUE << "a <= b: " << RESET << (a <= b) << std::endl;
	std::cout << BLUE << "a == b: " << RESET << (a == b) << std::endl;
	std::cout << BLUE << "a != b: " << RESET << (a != b) << std::endl;

	std::cout << MAGENTA << "a = " << RESET << a << std::endl;
	std::cout << MAGENTA << "++a = " << RESET << ++a << std::endl;
	std::cout << MAGENTA << "a++ = " << RESET << a++ << std::endl;
	std::cout << MAGENTA << "a = " << RESET << a << std::endl;

	std::cout << CYAN << "a = " << RESET << a << std::endl;
	std::cout << CYAN << "--a = " << RESET << --a << std::endl;
	std::cout << CYAN << "a-- = " << RESET << a-- << std::endl;
	std::cout << CYAN << "a = " << RESET << a << std::endl;


	std::cout << BRIGHT_CYAN << "Min of a and b: " << RESET << Fixed::min(a, b) << std::endl;
	std::cout << BRIGHT_CYAN << "Max of a and b: " << RESET << Fixed::max(a, b) << std::endl;
	std::cout << BRIGHT_CYAN << "Min of e and f: " << RESET << Fixed::min(e, f) << std::endl;
	std::cout << BRIGHT_CYAN << "Max of e and f: " << RESET << Fixed::max(e, f) << std::endl;

	std::cout << WHITE << "a as integer: " << RESET << a.toInt() << std::endl;
	std::cout << WHITE << "b as integer: " << RESET << b.toInt() << std::endl;
	std::cout << WHITE << "c as float: " << RESET << c.toFloat() << std::endl;
	std::cout << WHITE << "d as float: " << RESET << d.toFloat() << std::endl;

	return 0;
}
