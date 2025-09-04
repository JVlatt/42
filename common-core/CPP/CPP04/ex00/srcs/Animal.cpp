#include "Animal.hpp"
#include "Colors.hpp"

Animal::Animal()
{
	m_type = "*?*";
	std::cout << BRIGHT_GREEN << "A new animal is born !"
		<< RESET << std::endl;
}

Animal::Animal(std::string _name)
{
	m_type = "*?*";
	std::cout << BRIGHT_GREEN << "A new " << m_type << " called "
		<< _name << " is born !"
		<< RESET << std::endl;
	m_name = _name;
}

Animal::Animal(std::string _name, std::string _type)
{
	m_type = _type;
	std::cout << BRIGHT_GREEN << "A new " << m_type << " called "
		<< _name << " is born !"
		<< RESET << std::endl;
	m_name = _name;
}

Animal::Animal(const Animal& _other)
{
	*this = _other;
}

Animal& Animal::operator=(const Animal& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << m_name << " the "
		<< m_type << " is dead !"
		<< RESET << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << m_name <<" : *Weird animal sound*" << std::endl;
}

std::string Animal::getType() const
{
	return (m_type);
}

std::string Animal::getName() const
{
	return (m_name);
}

void Animal::whoAmI() const
{
	std::cout << CYAN << "Hello I am " << m_name
		<< " and I am a " << m_type
		<< RESET << std::endl;
}
