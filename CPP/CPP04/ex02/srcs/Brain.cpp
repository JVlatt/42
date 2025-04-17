#include "Brain.hpp"
#include "Colors.hpp"

Brain::Brain()
{
	std::cout << BRIGHT_GREEN << "Created Brain !"
		<< RESET << std::endl;
}

Brain::Brain(const Brain& _other)
{
	*this = _other;
}

Brain& Brain::operator=(const Brain& _other)
{
	if (this != &_other)
	{
		for (int i = 0; i < 100 ; ++i)
			m_ideas[i] = _other.m_ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << RED << "Destroyed Brain !"
		<< RESET << std::endl;
}
