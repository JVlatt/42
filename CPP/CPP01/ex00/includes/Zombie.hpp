#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#include "Colors.hpp"

class Zombie {

private:
	std::string m_name;

public:
	Zombie(std::string _name) : m_name(_name) {}
	~Zombie();
	void	announce(void);
};

Zombie	*newZombie( std::string _name );
void	randomChump( std::string _name );

#endif
