#include "Character.hpp"

Character::Character() : m_name("Unnamed") {}

Character::Character(const Character& _other) : m_name(_other.m_name), m_inventory(_other.m_inventory)
{
}

Character::Character(const std::string _name) : m_name(_name) {}

Character& Character::operator=(const Character& _other)
{
	if (this != &_other) {
		m_name = _other.m_name;
		m_inventory = _other.m_inventory;
	}
	return (*this);
}

Character::~Character()
{

}

std::string const &Character::getName() const
{
	return (m_name);
}

void Character::equip(AMateria *m)
{
	m_inventory.add(m);
}

void Character::unequip(int idx)
{
	m_inventory.removeAt(idx);
}

void Character::use(int idx, ICharacter &target)
{
	AMateria	*materia;

	materia = m_inventory.getAt(idx);
	if (materia)
	{
		materia->use(target);
	}
}
