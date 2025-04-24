#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << GREEN
		<< "A New PresidentialForm got printed !\n"
		<< RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
:	AForm("Presidential", false, 25, 5), m_target(_target)
{
	std::cout << GREEN
		<< "A New PresidentialForm which target "
		<< m_target << " got printed !\n"
		<< RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _other)
:	AForm(_other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& _other)
{
	if (this != &_other)
	{
		m_target = _other.m_target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED
		<< getName() << " the PresidentialForm got destroyed"
		<< RESET << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << BRIGHT_GREEN
		<< m_target
		<< " has been pardoned by Zaphod Beeblebrox !"
		<< RESET << std::endl;
}
