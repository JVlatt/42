#include <iostream>

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Scav");

	scav.attack("Clap");
	scav.guardGate();
	return (0);
}
