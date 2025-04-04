#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <ostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& _other);
	Fixed(const int _iValue);
	Fixed(const float _fValue);
	~Fixed();

	Fixed& operator=(const Fixed& _other);

	int		getRawBits(void) const;
	void	setRawBits(int const _raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	private:
	int					_value;
	static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
