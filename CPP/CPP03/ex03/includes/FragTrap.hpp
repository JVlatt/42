#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& _other);
	FragTrap(std::string _name);
	FragTrap& operator=(const FragTrap& _other);
	virtual ~FragTrap();

	void	highFivesGuys(void);
};

#endif
