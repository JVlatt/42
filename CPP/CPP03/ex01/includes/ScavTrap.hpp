#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& _other);
	ScavTrap(std::string _name);
	ScavTrap& operator=(const ScavTrap& _other);
	~ScavTrap();

	void attack(const std::string& _target);
	void	guardGate();
};

#endif
