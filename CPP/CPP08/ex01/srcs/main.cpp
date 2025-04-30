#include <cstdlib>
#include <ctime>

#include "Colors.hpp"
#include "Span.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED
			<< "Use ./span <number_of_elements> !"
			<< RESET << std::endl;
		return (1);
	}
	srand(time(NULL));
	int size;
	try
	{
		size = std::atoi(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: "  << e.what() << '\n';
		return (1);
	}

	if (size < 0)
	{
		std::cout << RED
			<< "Size cannot be negative !"
			<< RESET << std::endl;
	}

	Span sp = Span(size);
	std::vector<int> numbers;
	for (int i = 0; i < size; ++i)
	{
		numbers.push_back(rand());
	}

	try
	{
		sp.addNumber(numbers.begin(),numbers.end());
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << '\n';
		return (1);
	}

	try
	{
		int min = sp.shortestSpan();
		std::cout << "shortest span : " << min << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << '\n';
		return (1);
	}

	try
	{
		std::cout << "longest span  : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Exception: " << e.what() << '\n';
		return (1);
	}
	return (0);
}
