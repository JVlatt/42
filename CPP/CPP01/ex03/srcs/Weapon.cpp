#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	m_type = _type;
}

const std::string &Weapon::getType()
{
	return (m_type);
}

void Weapon::setType(const std::string _type)
{
	m_type = _type;
}
