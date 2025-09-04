#include "HumanA.hpp"
#include "Colors.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon)
		: m_name(_name), m_weapon(_weapon)
{

}

void HumanA::attack()
{
	std::cout << GREEN << m_name << RESET << " attacks with their "
		<< GREEN << m_weapon.getType() << RESET <<std::endl;
}

