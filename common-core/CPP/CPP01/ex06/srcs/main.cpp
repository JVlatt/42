#include "Harl.hpp"
#include "Colors.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Wrong Number of Arguments" << RESET << std::endl;
		return (1);
	}
	Harl		harl;
	std::string	level;

	level = argv[1];
	harl.complain(level);
	return (0);
}
