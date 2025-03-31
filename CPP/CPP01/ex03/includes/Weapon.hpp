#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

private:
	std::string	m_type;

public:
	Weapon(std::string _type) : m_type(_type) {}
	inline const std::string& getType() {return m_type;}
	inline void	setType(const std::string _type) {m_type = _type;}
};

#endif
