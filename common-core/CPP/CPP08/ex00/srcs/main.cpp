#include "Colors.hpp"
#include "easyfind.hpp"
#include <vector>

int main()
{
	std::cout << GREEN
		<< "Array :"
		<< RESET << std::endl;
	std::vector<int> array;
	for (int i = 0; i < 10; ++i)
	{
		array.push_back(i);
		std::cout << YELLOW << i << " ";
	}
	std::cout << RESET << std::endl;
	std::cout << CYAN
		<< "Searching '3' : "
		<< RESET << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(array,3);
		std::cout << GREEN
			<< "Found "<< *result
			<< RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED
			<< e.what()
			<< RESET << std::endl;
	}
	std::cout << CYAN
		<< "Searching '-1' : "
		<< RESET << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(array,-1);
		std::cout << GREEN
			<< "Found "<< *result
			<< RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED
			<< e.what()
			<< RESET << std::endl;
	}
	std::cout << CYAN
		<< "Searching '10' : "
		<< RESET << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(array,10);
		std::cout << GREEN
			<< "Found "<< *result
			<< RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED
			<< e.what()
			<< RESET << std::endl;
	}
	return (0);
}
