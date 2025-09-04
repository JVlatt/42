#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	input;

	if (argc == 1)
	{
		harl.complain("UNKNOWN");
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		input = argv[i];
		harl.complain(argv[i]);
	}
	return (0);
}
