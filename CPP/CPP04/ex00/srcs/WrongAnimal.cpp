#include "WrongAnimal.hpp"
#include "Colors.hpp"

WrongAnimal::WrongAnimal()
{
	m_type = "*?*";
	std::cout << BRIGHT_GREEN << "A new WrongAnimal is born !"
		<< RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string _name)
{
	m_type = "*?*";
	std::cout << BRIGHT_GREEN << "A new " << m_type << " called "
		<< _name << " is born !"
		<< RESET << std::endl;
	m_name = _name;
}

WrongAnimal::WrongAnimal(std::string _name, std::string _type)
{
	m_type = _type;
	std::cout << BRIGHT_GREEN << "A new " << m_type << " called "
		<< _name << " is born !"
		<< RESET << std::endl;
	m_name = _name;
}

WrongAnimal::WrongAnimal(const WrongAnimal& _other)
{
	*this = _other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << m_name << " the "
		<< m_type << " is dead !"
		<< RESET << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << m_name <<" : *Weird WrongAnimal sound*" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (m_type);
}

std::string WrongAnimal::getName() const
{
	return (m_name);
}

void WrongAnimal::whoAmI() const
{
	std::cout << CYAN << "Hello I am " << m_name
		<< " and I am a " << m_type
		<< RESET << std::endl;
}
