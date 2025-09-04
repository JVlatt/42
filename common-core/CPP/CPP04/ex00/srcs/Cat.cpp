#include "Cat.hpp"
#include "Colors.hpp"

Cat::Cat()
{
	std::cout << BRIGHT_GREEN << "A new Cat is born !"
		<< RESET << std::endl;
	m_type = "Cat";
}

Cat::Cat(std::string _name)
	: Animal(_name, "Cat")
{
}

Cat::Cat(const Cat& _other)
	: Animal(_other)
{

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
}

void Cat::makeSound() const
{
	std::cout << m_name << " : Moewwww !" << std::endl;
}
