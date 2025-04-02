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

	int start, end;

	for (int i = 1; i < argc; ++i)
	{
		start = 0;
		end = 0;
		while (argv[i][start] == ' ')
			start++;
		while (argv[i][end + 1])
			end++;
		while (argv[i][end] == ' ')
			end--;
		std::cout << RED;
		if (start <= end)
		{
			for (int j = start; j < end + 1; ++j)
			{
				std::cout << (char)std::toupper(argv[i][j]);
			}
			if (i < argc - 1)
				std::cout << " ";
		}
	}
	std::cout << RESET << std::endl;
	return (0);
}
