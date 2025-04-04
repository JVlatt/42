#ifndef FIXED_HPP
#define FIXED_HPP

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
	int					_value;
	static const int	_bits = 8;
};

#endif
