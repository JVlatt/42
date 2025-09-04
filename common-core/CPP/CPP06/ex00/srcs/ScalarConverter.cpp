#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cerrno>

#include "ScalarConverter.hpp"
#include "Colors.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& _other)
{
	*this = _other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& _other)
{
	(void) _other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool checkLitteralChar(std::string _input)
{
	return (_input.length() == 3 && _input[0] == '\'' && _input[2] == '\'');
}

static double get_double_value(const std::string &input)
{
	double output;
	char *last;

	errno = 0;
	output = std::strtod(input.c_str(), &last);
	if (*last && *last != 'f')
	{
		throw(std::invalid_argument("Input has invalid format"));
		return (0);
	}
	if (errno == ERANGE)
	{
		throw(std::range_error("Input is out of range"));
		return (0);
	}
	return (output);
}

static void displayCharValue(double _input)
{
	std::cout <<"char: ";
	if (_input < 0 || _input > 127)
		std::cout << RED << "invalid (not ASCII)" << RESET << std::endl;
	else if (std::isnan(_input))
		std::cout << RED << "invalid (not a number)" << RESET << std::endl;
	else if (!std::isprint(static_cast<char>(_input)))
		std::cout << RED << "invalid (not printable)" << RESET << std::endl;
	else
	std::cout << GREEN << "'" << static_cast<char>(_input) << "'" << RESET <<std::endl;
}

static void displayIntValue(double _input)
{
	std::cout << "int: ";
	if (_input < static_cast<double>(INT_MIN) || _input > static_cast<double>(INT_MAX))
		std::cout << RED << "invalid (overflow)" << RESET << std::endl;
	else if (std::isnan(_input))
		std::cout << RED << "invalid (not a number)" << RESET << std::endl;
	else
		std::cout << GREEN << static_cast<int>(_input) << RESET << std::endl;
}

static void displayFloatValue(double _input)
{
	std::cout << "float: ";
	std::cout << GREEN
		<< std::fixed << std::setprecision(1)
		<< static_cast<float>(_input) << "f"
		<< RESET << std::endl;
}

static void displayDoubleValue(double _input)
{
	std::cout << "double: ";
	std::cout << GREEN
		<< std::fixed << std::setprecision(1)
		<< _input
		<< RESET << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	double output;
	char c;

	if (checkLitteralChar(input))
	{
		c = input[1];
		output = static_cast<double>(c);
	}
	else
	{
		try
		{
			output = get_double_value(input);
		}
		catch (const std::exception &e)
		{
			std::cout << BRIGHT_RED
				<< "Conversion Error: " << e.what()
				<< RESET << std::endl;
			return;
		}
	}
	displayCharValue(output);
	displayIntValue(output);
	displayFloatValue(output);
	displayDoubleValue(output);
}
