#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << YELLOW << m_name << "is alive" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << m_name << ": Byeeeeee" << RESET << std::endl;
}

void Zombie::announce(void)
{
	std::cout << GREEN << m_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
