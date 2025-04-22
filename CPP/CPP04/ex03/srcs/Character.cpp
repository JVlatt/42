#include "Character.hpp"

Character::Character()
{

}

Character::Character(const Character& _other)
{

}

Character& Character::operator=(const Character& _other)
{

}

Character::~Character()
{

}

std::string const &Character::getName() const
{
	// TODO: insérer une instruction return ici
}

void Character::equip(AMateria *m)
{
}

void Character::unequip(int idx)
{
}

void Character::use(int idx, ICharacter &target)
{
	AMateria	*materia;

	materia = m_inventory->getAt(idx);
	if (materia)
	{
		materia->use(target);
		m_inventory->removeAt(idx);
	}
}
