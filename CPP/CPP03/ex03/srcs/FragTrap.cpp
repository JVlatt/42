#include "Colors.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GREEN
		<< "A New FragTrap is alive !"
		<< RESET << std::endl;
	this->m_hp = 100;
	this->m_energy = 100;
	this->m_attack = 30;
}

FragTrap::FragTrap(const FragTrap& _other)
	: ClapTrap(_other)
{
}

FragTrap::FragTrap(std::string _name)
{
	std::cout << GREEN << "FragTrap "
		<< _name << " is alive !"
		<< RESET << std::endl;
	m_name = _name;
	m_hp = 100;
	m_energy = 100;
	m_attack = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& _other)
{
	if (this != &_other)
	{
		m_name = _other.m_name;
		m_hp = _other.m_hp;
		m_energy = _other.m_energy;
		m_attack = _other.m_attack;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap "
		<< m_name << " is dead !"
		<< RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap "
		<< m_name << " requests a highfive !"
		<< RESET << std::endl;
}
