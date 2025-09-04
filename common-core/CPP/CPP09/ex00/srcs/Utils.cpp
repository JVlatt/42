#include "Utils.hpp"
#include <climits>
#include <stdexcept>

int ft_atoi(char const *str)
{
	int result = 0;
	bool negate;

	if (str == NULL || *str == '\0')
		throw std::invalid_argument("null or empty string argument");
	while (std::isspace(*str))
		++str;
	negate = (*str == '-');
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		throw std::invalid_argument("sign character only.");
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			while (std::isspace(*str))
				++str;
			if (*str)
				throw std::invalid_argument("invalid input string");
			else
				break;
		}
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && *str - '0' > INT_MAX % 10))
			throw std::overflow_error("overflow occurred");
		if (result < INT_MIN / 10 || (result == INT_MIN / 10 && *str - '0' > -(INT_MIN % 10)))
			throw std::overflow_error("underflow occurred");
		result = result * 10 + (*str - '0');
		++str;
	}
	return negate ? -result : result;
}

float ft_atof(char const *str)
{
	float result = 0;
	float decimal = 0;
	float weight = 1;
	bool negate;

	if (str == NULL || *str == '\0')
		throw std::invalid_argument("null or empty string argument");
	while (std::isspace(*str))
		++str;
	negate = (*str == '-');
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		throw std::invalid_argument("sign character only.");
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			if (*str == '.')
			{
				++str;
				break;
			}
			while (std::isspace(*str))
				++str;
			if (*str)
				throw std::invalid_argument("invalid input string");
			else
				break;
		}
		result = result * 10 + (*str - '0');
		++str;
	}

	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			if (weight == 0)
				throw std::invalid_argument("invalid input string");

			while (std::isspace(*str))
				++str;

			if (*str)
				throw std::invalid_argument("invalid input string");
			else
				break;
		}
		decimal = decimal * 10 + (*str - '0');
		weight *= 10;
		++str;
	}
	decimal /= weight;
	return negate ? -(result + decimal) : (result + decimal);
}
