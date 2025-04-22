#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "AMateria.hpp"

class Inventory
{
public:
	Inventory();
	Inventory(const Inventory& _other);
	Inventory& operator=(const Inventory& _other);
	~Inventory();

	void add(AMateria *_materia);
	void clear(void);
	AMateria *getAt(int _id);
	void removeAt(int _id);

private:
	AMateria *m_materias[4];
};

#endif
