#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(const ScavTrap& _other);
	ScavTrap(std::string _name);
	ScavTrap& operator=(const ScavTrap& _other);
	~ScavTrap();

	void	guardGate(void);
	void	attack(const std::string& _target);
};

#endif
