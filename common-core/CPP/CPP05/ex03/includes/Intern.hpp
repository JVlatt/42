#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& _other);
	Intern& operator=(const Intern& _other);
	~Intern();

	AForm *makeForm(const std::string& _formName, const std::string& _target);
};

#endif
