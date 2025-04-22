#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	m_type = type;
}

AMateria::~AMateria()
{

}

std::string const &AMateria::getType() const
{
	return (m_type);
}

void AMateria::use(ICharacter &target)
{
	(void) target;
}
