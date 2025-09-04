#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	randomChump("Victor");
	zombie = newZombie("Spencer");
	zombie->announce();
	delete(zombie);
	return (0);
}
