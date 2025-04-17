#include "AAnimal.hpp"
#include "Colors.hpp"

AAnimal::AAnimal()
{
	m_type = "*?*";
	std::cout << BRIGHT_GREEN << "A new AAnimal is born !"
		<< RESET << std::endl;
}

AAnimal::AAnimal(std::string _name)
{
	m_type = "*?*";
	std::cout << BRIGHT_GREEN << "A new " << m_type << " called "
		<< _name << " is born !"
		<< RESET << std::endl;
	m_name = _name;
}

AAnimal::AAnimal(std::string _name, std::string _type)
{
	m_type = _type;
	std::cout << BRIGHT_GREEN << "A new " << m_type << " called "
		<< _name << " is born !"
		<< RESET << std::endl;
	m_name = _name;
}

AAnimal::AAnimal(const AAnimal& _other)
{
	*this = _other;
}

AAnimal& AAnimal::operator=(const AAnimal& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << RED << m_name << " the "
		<< m_type << " is dead !"
		<< RESET << std::endl;
}

std::string AAnimal::getType() const
{
	return (m_type);
}

std::string AAnimal::getName() const
{
	return (m_name);
}

void AAnimal::whoAmI() const
{
	std::cout << CYAN << "Hello I am " << m_name
		<< " and I am a " << m_type
		<< RESET << std::endl;
}
