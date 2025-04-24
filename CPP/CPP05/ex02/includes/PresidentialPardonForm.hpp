#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm& _other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& _other);
	~PresidentialPardonForm();

	virtual void executeAction() const;

private:
	std::string	m_target;
};


#endif
