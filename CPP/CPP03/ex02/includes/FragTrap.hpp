#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap& _other);
	FragTrap(std::string _name);
	FragTrap& operator=(const FragTrap& _other);
	~FragTrap();

	void	highFivesGuys(void);

private:

};

#endif
