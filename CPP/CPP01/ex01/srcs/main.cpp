#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(6,"Fred");
	for (int i = 0; i < 6; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}
