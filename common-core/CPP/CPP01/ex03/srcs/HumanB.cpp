#include "HumanB.hpp"
#include "Colors.hpp"

HumanB::HumanB(std::string _name)
{
	m_weapon = NULL;
	m_name = _name;
}

void	HumanB::attack()
{
	if (!m_weapon)
	{
		std::cout << GREEN << m_name << RESET << " tries to attack "
			<< RED << "but forgot his weapon !" << RESET << std::endl;
	}
	else
	{
		std::cout << GREEN << m_name << RESET << " attacks with their "
			<< GREEN << m_weapon->getType() << RESET <<std::endl;
	}
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	m_weapon = &_weapon;
}
