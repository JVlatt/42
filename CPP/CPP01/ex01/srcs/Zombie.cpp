#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << YELLOW << "A Zombie is alive" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << m_name << ": Byeeeeee" << RESET << std::endl;
}

Zombie::Zombie(std::string _name)
	: m_name(_name)
{
}

void Zombie::setName(std::string _name)
{
	m_name = _name;
}

void Zombie::announce(void)
{
	std::cout << GREEN << m_name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
