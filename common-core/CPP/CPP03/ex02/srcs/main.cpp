#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap scav("Scav");
	FragTrap frag("Frag");

	scav.attack("Frag");
	frag.takeDamage(20);
	scav.guardGate();
	frag.attack("Scav");
	scav.takeDamage(30);
	frag.highFivesGuys();
	return (0);
}
