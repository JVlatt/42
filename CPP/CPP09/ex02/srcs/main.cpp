#include <cstdlib>

#include "Colors.hpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> vInt;
	std::cout << "Before : \n";
	for (int i = 1; i < argc; ++i)
	{
		vInt.push_back(std::atoi(argv[i]));
	}
	printArray(vInt, 1);
	std::cout << std::endl;
	mergeInsterFJ<std::vector<int> >(vInt, 1);
	std::cout << "After : \n";
	printArray(vInt, 1);
	return (0);
}
