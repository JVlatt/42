#ifndef FIXED_HPP
#define FIXED_HPP

#pragma once

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& _other);
	Fixed& operator=(const Fixed& _other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const _raw);

private:
	int					m_value;
	static const int	m_bits = 8;
};

#endif
