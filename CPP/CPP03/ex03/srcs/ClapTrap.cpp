#include "Colors.hpp"
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << GREEN
		<< "A New Claptrap is alive !"
		<< RESET << std::endl;
	m_hp = 10;
	m_energy = 10;
	m_attack = 0;
}

ClapTrap::ClapTrap(std::string _name)
{
	std::cout << GREEN << "ClapTrap "
		<< _name << " is alive !"
		<< RESET << std::endl;
	m_name = _name;
	m_hp = 10;
	m_energy = 10;
	m_attack = 0;
}

ClapTrap::ClapTrap(const ClapTrap& _other)
{
	*this = _other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& _other)
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

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap "
		<< m_name << " is dead !"
		<< RESET << std::endl;
}

void ClapTrap::attack(const std::string &_target)
{
	if (m_energy == 0)
	{
		std::cout << CYAN
			<< m_name << " is exhausted !"
			<< RESET << std::endl;
		return ;
	}
	std::cout << YELLOW
		<< m_name << " attacks " << _target
		<< ", causing " << m_attack
		<< " points of damage !"
		<< RESET << std::endl;
	m_energy -= 1;
}

void ClapTrap::takeDamage(unsigned int _amount)
{
	std::cout << BRIGHT_RED
		<< m_name << " took " << _amount
		<< " points of damage"
		<< " and is now at " << m_hp - _amount
		<< " points of health !"
		<< RESET << std::endl;
	m_hp -= _amount;
}

void ClapTrap::beRepaired(unsigned int _amount)
{
	if (m_energy == 0)
	{
		std::cout << CYAN
			<< m_name << " is exhausted !"
			<< RESET << std::endl;
		return ;
	}
	std::cout << BRIGHT_GREEN
		<< m_name << " heal it self for " << _amount
		<< " and is now at " << m_hp + _amount
		<< " points of health !"
		<< RESET << std::endl;
	m_energy -= 1;
	m_hp += _amount;
}

