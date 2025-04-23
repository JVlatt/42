#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal *meta = new Animal("Meta");
		const Animal *dog = new Dog("Bruno");
		const Animal *cat = new Cat("Felix");

		meta->whoAmI();
		dog->whoAmI();
		cat->whoAmI();
		dog->makeSound();
		cat->makeSound();
		meta->makeSound();

		delete (meta);
		delete (dog);
		delete (cat);
	}
	{
		const WrongAnimal *meta = new WrongAnimal("Meta");
		const WrongAnimal *cat = new WrongCat("Felix");

		meta->whoAmI();
		cat->whoAmI();
		cat->makeSound();
		meta->makeSound();

		delete (meta);
		delete (cat);
	}
	return (0);
}
