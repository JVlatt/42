#include "Dog.hpp"
#include "Colors.hpp"

Dog::Dog()
{
	std::cout << BRIGHT_GREEN << "A new dog is born !"
		<< RESET << std::endl;
	m_type = "Dog";
	m_brain = new Brain();
}

Dog::Dog(const Dog& _other)
	: Animal(_other)
{
	if (_other.m_brain)
		m_brain = _other.m_brain;
	else
		m_brain = new Brain();
}

Dog::Dog(std::string _name)
	: Animal(_name, "Dog")
{
	m_brain = new Brain();
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
	delete (m_brain);
}

void Dog::makeSound(void) const
{
	std::cout << m_name << " : Bark bark !" << std::endl;
}
