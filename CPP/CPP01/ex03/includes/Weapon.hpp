#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

private:
	std::string	m_type;

public:
	Weapon(std::string _type);
	const	std::string& getType();
	void	setType(const std::string _type);
};

#endif
