#include "Ice.hpp"

Ice::Ice()
{

}

Ice::Ice(const Ice& _other)
{
	*this = _other;

}

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
