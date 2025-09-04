#include "Ice.hpp"
#include "Colors.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& _other) : AMateria(_other) {}

Ice& Ice::operator=(const Ice& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

Ice::~Ice()
{

}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << BRIGHT_CYAN
		<< "* shoots an ice bolt at " << target.getName()
		<< " *" << RESET << std::endl;
}
