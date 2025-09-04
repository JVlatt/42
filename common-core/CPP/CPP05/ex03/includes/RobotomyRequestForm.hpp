#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm& _other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& _other);
	~RobotomyRequestForm();

	virtual void executeAction() const;

private:
	std::string	m_target;
};

#endif
