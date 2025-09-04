#include "ScavTrap.hpp"
#include "Colors.hpp"

ScavTrap::ScavTrap()
{
	std::cout << GREEN
		<< "A New ScavTrap is alive !"
		<< RESET << std::endl;
	m_hp = 100;
	m_energy = 50;
	m_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap& _other)
	: ClapTrap(_other)
{

}

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << GREEN << "ScavTrap "
		<< _name << " is alive !"
		<< RESET << std::endl;
	m_name = _name;
	m_hp = 100;
	m_energy = 50;
	m_attack = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& _other)
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

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap "
		<< m_name << " is dead !"
		<< RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap "
		<< m_name << " is now in Gatekeeper mode !"
		<< RESET << std::endl;
}

void ScavTrap::attack(const std::string &_target)
{
	if (m_energy == 0)
	{
		std::cout << CYAN << "ScavTrap "
			<< m_name << " is exhausted !"
			<< RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "ScavTrap "
		<< m_name << " use a scavenger attack on " << _target
		<< ", causing " << m_attack
		<< " points of damage !"
		<< RESET << std::endl;
	m_energy -= 1;
}
