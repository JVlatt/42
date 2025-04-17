#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(const AMateria& _other)
{
	*this = _other;
}

AMateria& AMateria::operator=(const AMateria& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

AMateria::~AMateria()
{

}

std::string const &AMateria::getType() const
{
	return (m_type);
}
