#include "Colors.hpp"
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED
			<< "Use ./RPN \"...\""
			<< RESET << std::endl;
		return (1);
	}
	parse_input(argv[1]);
	return (0);
}
