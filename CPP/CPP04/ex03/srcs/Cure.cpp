#include "Colors.hpp"
#include "Cure.hpp"

Cure::Cure()
{

}

Cure::Cure(const Cure& _other)
{
	*this = _other;
}

Cure& Cure::operator=(const Cure& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

Cure::~Cure()
{

}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << BRIGHT_GREEN
		<< "* heals " << target.getName()
		<< "\'s wounds *" << RESET << std::endl;
}
