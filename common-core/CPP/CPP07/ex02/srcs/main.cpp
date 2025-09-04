#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#include "Colors.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << GREEN
		<< "=== Array Init =="
		<< RESET << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << "✅" << std::endl;
	std::cout << GREEN
		<< "=== Copy & Assign =="
		<< RESET << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cout << RED << " ❌ didn't save the same value!!" << RESET << std::endl;
			return 1;
		}
	}
	std::cout << "✅" << std::endl;
	std::cout << GREEN
		<< "=== Invalid Index & Out Of Range =="
		<< RESET << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << " ❌ " << e.what() << RESET << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << " ❌ " << e.what() << RESET << '\n';
	}
	std::cout << "✅" << std::endl;

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << GREEN
		<< "=== Empty =="
		<< RESET << std::endl;
	Array<int> empty;
	try
	{
		empty[0] = 0;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << " ❌ " <<  e.what() << RESET << '\n';
	}
	std::cout << "✅" << std::endl;
	delete [] mirror;
	return 0;
}
