#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {

private:
	std::string m_name;
	Weapon& m_weapon;
public:
	HumanA(std::string _name, Weapon &_weapon);
	void	attack();
};

#endif
