#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << RED << m_name << ": Byeeeeee" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << GREEN << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
