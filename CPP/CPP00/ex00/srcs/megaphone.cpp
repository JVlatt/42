#include <iostream>
#include "Colors.hpp"

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << RED
			<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
			<< RESET << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		std::cout << RED;
		for (int j = 0; argv[i][j]; ++j)
		{
			std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << " ";
	}
	std::cout << RESET << std::endl;
	return (0);
}
