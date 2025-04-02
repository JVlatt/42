#include "Cat.hpp"
#include "Colors.hpp"

Cat::Cat()
{
	std::cout << BRIGHT_GREEN << "A new Cat is born !"
		<< RESET << std::endl;
	m_type = "Cat";
	m_brain = new Brain();
}

Cat::Cat(std::string _name)
	: Animal(_name, "Cat")
{
	m_brain = new Brain();
}

Cat::Cat(const Cat& _other)
	: Animal(_other)
{
	if (_other.m_brain)
		m_brain = _other.m_brain;
	else
		m_brain = new Brain();
}

Cat& Cat::operator=(const Cat& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << RED
		<< m_name << " : meooooooh !"
		<< RESET << std::endl;
	delete (m_brain);
}

void Cat::makeSound() const
{
	std::cout << m_name << " : Moewwww !" << std::endl;
}
