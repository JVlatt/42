#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << RED << m_name << ": Byeeeeee" << std::endl;
}

Zombie::Zombie(std::string _name)
	: m_name(_name)
{
}

void Zombie::announce(void)
{
	std::cout << GREEN << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
