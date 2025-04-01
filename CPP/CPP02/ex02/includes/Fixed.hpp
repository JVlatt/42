#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>

#pragma once

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& _other);
	Fixed(const int _iValue);
	Fixed(const float _fValue);
	~Fixed();

	bool operator>(const Fixed& _other) const;
	bool operator<(const Fixed& _other) const;
	bool operator>=(const Fixed& _other) const;
	bool operator<=(const Fixed& _other) const;
	bool operator==(const Fixed& _other) const;
	bool operator!=(const Fixed& _other) const;

	Fixed& operator=(const Fixed& _other);
	Fixed operator+(const Fixed& _other) const;
	Fixed operator-(const Fixed& _other) const;
	Fixed operator*(const Fixed& _other) const;
	Fixed operator/(const Fixed& _other) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const _raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					m_value;
	static const int	m_bits = 8;
};

#endif
