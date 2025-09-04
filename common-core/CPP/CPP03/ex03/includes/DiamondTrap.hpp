#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& _other);
	DiamondTrap& operator=(const DiamondTrap& _other);
	virtual ~DiamondTrap();

	void	whoAmI();
	using ScavTrap::attack;

private:
	std::string m_name;
};

#endif
