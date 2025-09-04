#include "WrongCat.hpp"
#include "Colors.hpp"

WrongCat::WrongCat()
{
	std::cout << BRIGHT_GREEN << "A new WrongCat is born !"
		<< RESET << std::endl;
	m_type = "WrongCat";
}

WrongCat::WrongCat(std::string _name)
	: WrongAnimal(_name, "WrongCat")
{
}

WrongCat::WrongCat(const WrongCat& _other)
	: WrongAnimal(_other)
{

}

WrongCat& WrongCat::operator=(const WrongCat& _other)
{
	if (this != &_other)
	{
		m_type = _other.m_type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED
		<< m_name << " : meooooooh !"
		<< RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << m_name << " : Moewwww !" << std::endl;
}
