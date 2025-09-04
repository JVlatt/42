#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
//	const Animal *meta = new Animal("Bruno");

	const Dog *dog = new Dog("Bruno");
	const Cat *cat = new Cat("Felix");

	dog->whoAmI();
	cat->whoAmI();
	dog->makeSound();
	cat->makeSound();

	delete (dog);
	delete (cat);
	return (0);
}
