#include "MathUtils.hpp"

int ft_atoi(char const *str)
{
	int result = 0;
	bool negate;

	if (str == NULL || *str == '\0')
		throw std::invalid_argument("null or empty string argument");
	negate = (str[0] == '-');
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		throw std::invalid_argument("sign character only.");
	while (*str)
	{
		if (*str < '0' || *str > '9')
			throw std::invalid_argument("invalid input string");
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && *str - '0' > INT_MAX % 10))
				throw std::overflow_error("overflow occurred");
		if (result < INT_MIN / 10 || (result == INT_MIN / 10 && *str - '0' > -(INT_MIN % 10)))
				throw std::overflow_error("underflow occurred");
		result = result * 10 - (*str - '0');
		++str;
	}
	return negate ? result : -result;
}

