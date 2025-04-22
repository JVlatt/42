#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{

}

MateriaSource::MateriaSource(const MateriaSource& _other)
	: m_inventory(_other.m_inventory)
{
}

MateriaSource& MateriaSource::operator=(const MateriaSource& _other)
{
	if (this != &_other)
	{
		m_inventory.clear();
		m_inventory = _other.m_inventory;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *m)
{
	m_inventory.add(m);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	return (m_inventory.find(type));
}
