#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal	*animals[10];

	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Dog("Bruno");
		else
			animals[i] = new Cat("Felix");
	}

	for (int i = 0; i < 10; ++i)
	{
		animals[i]->whoAmI();
		animals[i]->makeSound();
	}

	for (int i = 0; i < 10; ++i)
	{
		delete(animals[i]);
	}
	return (0);
}

