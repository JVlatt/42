#include <iostream>

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap = ClapTrap("Clap");
	ClapTrap trap = ClapTrap("Trap");

	clap.attack("Trap");
	trap.takeDamage(0);
	trap.beRepaired(5);
	return (0);
}
