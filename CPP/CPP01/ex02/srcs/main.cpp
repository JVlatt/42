#include <string>
#include <iostream>

#include "Colors.hpp"

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << GREEN << "Address            : " << RESET << std::endl;
	std::cout << YELLOW << "String              : " << &string << RESET << std::endl;
	std::cout << CYAN << "Pointer Address     : " << &stringPTR << RESET << std::endl;
	std::cout << CYAN << "Pointer pointing to : " << stringPTR << RESET << std::endl;
	std::cout << BLUE << "Reference           : " << &stringREF << RESET << std::endl;

	std::cout << GREEN << "\nValues : " << RESET << std::endl;
	std::cout << YELLOW << "String    : " << string << RESET << std::endl;
	std::cout << CYAN << "Pointer   : " << *stringPTR << RESET << std::endl;
	std::cout << BLUE << "Reference : " << stringREF << RESET << std::endl;
}
