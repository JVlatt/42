#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
	Dog();
	Dog(std::string _name);
	Dog(const Dog& _other);
	Dog& operator=(const Dog& _other);
	~Dog();

	void makeSound() const;

	private:
	Brain	*m_brain;
};

#endif
