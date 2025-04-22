#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"
#include "Inventory.hpp"

class Character : public ICharacter
{

	public:
	Character();
	Character(const Character& _other);
	Character(const std::string _name);
	Character& operator=(const Character& _other);
	~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	private:
	std::string	m_name;
	Inventory	*m_inventory;
};

#endif
