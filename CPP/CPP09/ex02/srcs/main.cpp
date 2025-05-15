#include <cstdlib>

#include "Colors.hpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> vInt;
	std::cout << "Before : ";
	for (int i = 1; i < argc; ++i)
	{
		vInt.push_back(std::atoi(argv[i]));
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	mergeInsterFJ<std::vector<int> >(vInt, 1);
	return (0);
}
