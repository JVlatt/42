#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

class HumanB {

private:
	std::string m_name;
	Weapon *m_weapon;
public:
	HumanB(std::string _name);
	void	attack();
	void	setWeapon(Weapon& _weapon);
};

#endif
