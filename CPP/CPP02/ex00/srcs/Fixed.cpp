#include <iostream>

#include "Colors.hpp"
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN << "Default constructor called"
		<< RESET << std::endl;
	m_value = 0;
}

Fixed::Fixed(const Fixed& _other)
{
	std::cout << BLUE << "Copy constructor called"
		<< RESET << std::endl;
	*this = _other;
}

Fixed& Fixed::operator=(const Fixed& _other)
{
	std::cout << CYAN << "Copy assignement operator called"
		<< RESET << std::endl;
	if (this != &_other)
		m_value = _other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called"
		<< RESET << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << YELLOW << "getRawBits function called"
		<< RESET << std::endl;
	return (m_value);
}

void Fixed::setRawBits(int const _raw)
{
	m_value = _raw;
}

