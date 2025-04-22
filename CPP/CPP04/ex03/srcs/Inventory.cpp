#include "Inventory.hpp"
#include "Colors.hpp"

Inventory::Inventory()
{

}

Inventory::Inventory(const Inventory& _other)
{

}

Inventory& Inventory::operator=(const Inventory& _other)
{

}

Inventory::~Inventory()
{
	clear();
}

void Inventory::add(AMateria *_materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!m_materias[i])
		{
			m_materias[i] = _materia;
			return ;
		}
	}
	std::cout << BRIGHT_RED
		<< "Cannot add Materia, Inventory is full"
		<< RESET << std::endl;
}

void Inventory::clear(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_materias[i])
		{
			delete (m_materias[i]);
		}
	}
}

AMateria *Inventory::getAt(int _id)
{
	if (m_materias[_id])
		return (m_materias[_id]);
	else
	{
		std::cout << BRIGHT_RED
			<< "No Materia at slot " << _id
			<< RESET << std::endl;
		return nullptr;
	}
}

void Inventory::removeAt(int _id)
{
	if (m_materias[_id])
		m_materias[_id] = NULL;
	else
	{
		std::cout << BRIGHT_RED
			<< "No Materia at slot " << _id
			<< RESET << std::endl;
	}
}
