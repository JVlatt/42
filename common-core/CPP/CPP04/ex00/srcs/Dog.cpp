#include "Dog.hpp"
#include "Colors.hpp"

Dog::Dog()
{
	std::cout << BRIGHT_GREEN << "A new dog is born !"
		<< RESET << std::endl;
	m_type = "Dog";
}

Dog::Dog(const Dog& _other)
	: Animal(_other)
{

}

Dog::Dog(std::string _name)
	: Animal(_name, "Dog")
{
}

Dog& Dog::operator=(const Dog& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED
		<< m_name << " : wooooooh !"
		<< RESET << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << m_name << " : Bark bark !" << std::endl;
}
