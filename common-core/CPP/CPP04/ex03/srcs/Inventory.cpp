#include "Inventory.hpp"
#include "Colors.hpp"

Inventory::Inventory()
{
	for (int i = 0; i < 4; ++i)
		m_materias[i] = NULL;
}

Inventory::Inventory(const Inventory& _other)
{
	for (int i = 0; i < 4; ++i) {
		if (_other.m_materias[i])
			m_materias[i] = _other.m_materias[i]->clone();
		else
			m_materias[i] = NULL;
	}
}

Inventory& Inventory::operator=(const Inventory& _other)
{
	if (this != &_other)
	{
		clear();
		for (int i = 0; i < 4; ++i) {
			if (_other.m_materias[i])
				m_materias[i] = _other.m_materias[i]->clone();
			else
				m_materias[i] = NULL;
		}
	}
	return (*this);
}

Inventory::~Inventory()
{
	clear();
}

void Inventory::add(AMateria *_materia)
{
	if (!_materia)
	{
		std::cout << BRIGHT_RED
		<< "Cannot add Materia, Invalid Materia"
		<< RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!m_materias[i])
		{
			if (isInInventory(_materia))
				m_materias[i] = _materia->clone();
			else
				m_materias[i] = _materia;
			std::cout << GREEN
				<< "Add Materia "
				<< _materia->getType()
				<< "(" << _materia << ")"
				<< " at slot " << i
				<< RESET << std::endl;
			return ;
		}
	}
	std::cout << BRIGHT_RED
		<< "Cannot add Materia "
		<< _materia->getType()
		<< ", Inventory is full"
		<< RESET << std::endl;
	if (!isInInventory(_materia))
	{
		delete (_materia);
	}
}

void Inventory::clear(void)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_materias[i])
		{
			std::cout << YELLOW
			<< "Cleaning Materia "
			<< m_materias[i]->getType()
			<< "(" << &m_materias[i] << ")"
			<< " at slot " << i
			<< RESET << std::endl;
			delete (m_materias[i]);
			//m_materias[i] = NULL;
		}
	}
}

AMateria *Inventory::getAt(int _id)
{
	if (_id < 0 || _id > 3)
	{
		std::cout << BRIGHT_RED
			<< "Invalid Slot Id : " << _id
			<< RESET << std::endl;
		return (NULL);
	}
	if (m_materias[_id])
	{
		std::cout << BRIGHT_GREEN
			<< "Materia "
			<< m_materias[_id]->getType()
			<< " found at slot "<< _id
			<< RESET << std::endl;
		return (m_materias[_id]);
	}
	else
	{
		std::cout << BRIGHT_RED
			<< "No Materia at slot " << _id
			<< RESET << std::endl;
		return (NULL);
	}
}

void Inventory::removeAt(int _id)
{
	if (_id < 0 || _id > 3)
	{
		std::cout << BRIGHT_RED
			<< "Invalid Slot Id : " << _id
			<< RESET << std::endl;
		return ;
	}
	if (m_materias[_id])
	{
		std::cout << BRIGHT_GREEN
			<< "Remove Materia "
			<< m_materias[_id]->getType()
			<< " at slot "<< _id
			<< RESET << std::endl;
		m_materias[_id] = NULL;
	}
	else
	{
		std::cout << BRIGHT_RED
			<< "No Materia at slot " << _id
			<< RESET << std::endl;
	}
}

AMateria *Inventory::find(std::string _name)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_materias[i] && m_materias[i]->getType() == _name)
		{
			return (m_materias[i]->clone());
		}
	}
	std::cout << BRIGHT_RED
			<< "Unknown Materia : \'" << _name
			<< "\'" << RESET << std::endl;
	return (NULL);
}

bool Inventory::isInInventory(AMateria *_materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_materias[i] == _materia)
			return (true);
	}
	return false;
}
