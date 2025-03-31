#include "HumanA.hpp"
#include "Colors.hpp"

void HumanA::attack()
{
	std::cout << GREEN << m_name << RESET << " attacks with their "
		<< GREEN << m_weapon.getType() << RESET <<std::endl;
}

