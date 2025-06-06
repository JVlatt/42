#include "DiamondTrap.hpp"
#include "Colors.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("DefaultDT_clap_name"), m_name("DefaultDT")
{
	std::cout << GREEN
		<< "A New DiamondTrap is alive !"
		<< RESET << std::endl;
	this->m_energy = 50;
}

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name"), m_name(_name)
{
	std::cout << GREEN << "DiamondTrap "
		<< m_name << " is alive !"
		<< RESET << std::endl;
	this->m_energy = 50;

	std::cout << BRIGHT_RED
		<< "I have : " << m_hp << " hps," << std::endl
		<< "I have : " << m_energy << " energy," << std::endl
		<< "I have : " << m_attack << " attack !" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& _other)
	: ClapTrap(_other), ScavTrap(_other), FragTrap(_other), m_name(_other.m_name)
{
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& _other)
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

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap "
		<< m_name << " is dead !"
		<< RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << CYAN
		<< "I am " << m_name
		<< " and my ClapTrap name is " << ClapTrap::m_name
		<< RESET << std::endl;

}
