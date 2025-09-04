#include "Zombie.hpp"

Zombie	*zombieHorde(int _n, std::string _name)
{
	if (_n <= 0)
		return (NULL);

	Zombie	*zombieHorde = new Zombie[_n];

	for (int i = 0; i < _n; ++i)
		zombieHorde[i].setName(_name);

	return (zombieHorde);
}
