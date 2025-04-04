#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#include "Colors.hpp"

class Zombie {
private:
	std::string m_name;

public:
	Zombie();
	Zombie(std::string _name);
	~Zombie();
	void	announce(void);
	void	setName(std::string _name);
};

Zombie	*zombieHorde(int _N, std::string _name);

#endif
