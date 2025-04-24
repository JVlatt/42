#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm& _other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& _other);
	~ShrubberyCreationForm();

	virtual void executeAction() const;

private:
	std::string	m_target;
};

#endif
