#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

Intern::Intern()
{
	std::cout << GREEN
		<< "A New Intern got hired"
		<< RESET << std::endl;
}

Intern::Intern(const Intern& _other)
{
	*this = _other;
}

Intern& Intern::operator=(const Intern& _other)
{
	(void) _other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << RED
		<< "An Intern got fired"
		<< RESET << std::endl;
}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*constructor[3])(const std::string&) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << BRIGHT_GREEN
				<< "Intern creates " << formName
				<< RESET << std::endl;
			return constructor[i](target);
		}
	}

	std::cout << BRIGHT_RED
		<< "ERROR : Intern couldn't find the form named: "
		<< formName
		<< RESET << std::endl;
	return NULL;
}
