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

Fixed::Fixed(const int _iValue)
{
	std::cout << MAGENTA << "Int constructor called"
		<< RESET << std::endl;
	m_value = _iValue << m_bits;
}

Fixed::Fixed(const float _fValue)
{
	std::cout << BRIGHT_MAGENTA << "Float constructor called"
		<< RESET << std::endl;
	m_value = static_cast<int>(roundf(_fValue * (1 << m_bits)));
}

Fixed& Fixed::operator=(const Fixed& _other)
{
	std::cout << CYAN << "Copy assignement operator called"
		<< RESET << std::endl;
	if (this != &_other)
		m_value = _other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
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

float Fixed::toFloat(void) const
{
	return (static_cast<float>(m_value) / (1 << m_bits));
}

int Fixed::toInt(void) const
{
	return (m_value >> m_bits);
}
