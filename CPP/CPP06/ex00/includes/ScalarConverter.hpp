#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& _other);
	ScalarConverter& operator=(const ScalarConverter& _other);
	~ScalarConverter();

public:
	static void convert(const std::string &literal);
};

#endif
