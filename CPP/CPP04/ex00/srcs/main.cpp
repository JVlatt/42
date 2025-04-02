#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	const Animal* meta = new Animal("Meta");
	const Animal* dog = new Dog("Bruno");
	const Animal* cat = new Cat("Felix");

	meta->whoAmI();
	dog->whoAmI();
	cat->whoAmI();
	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	delete (meta);
	delete (dog);
	delete (cat);

	return (0);
}

