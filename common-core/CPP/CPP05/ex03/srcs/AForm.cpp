#include "AForm.hpp"
#include "Colors.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: m_name("Default"), m_bisSigned(false), m_signRequirement(50), m_execRequirement(10)
{
	std::cout << GREEN
		<< "A New AForm got printed !\n"
		<< *this
		<< RESET << std::endl;
}

AForm::AForm(std::string _name, bool _isSigned, const int _signRequirement, const int _execRequirement)
	: m_name(_name), m_bisSigned(_isSigned),
	m_signRequirement(_signRequirement), m_execRequirement(_execRequirement)
{
	if (_signRequirement < 1)
		throw AForm::GradeTooHighException("Sign Grade too high : Grade must be within 1-150 range !");
	else if (_signRequirement > 150)
		throw AForm::GradeTooLowException("Sign Grade too low : Grade must be within 1-150 range !");
	if (_execRequirement < 1)
		throw AForm::GradeTooHighException("Exec Grade too high : Grade must be within 1-150 range !");
	else if (_execRequirement > 150)
		throw AForm::GradeTooLowException("Exec Grade too low : Grade must be within 1-150 range !");
	std::cout << GREEN
		<< "A New AForm got printed !\n"
		<< *this
		<< RESET << std::endl;
}

AForm::AForm(const AForm& _other)
	: m_name(_other.m_name), m_bisSigned(_other.m_bisSigned),
	m_signRequirement(_other.m_signRequirement), m_execRequirement(_other.m_execRequirement) {}

AForm& AForm::operator=(const AForm& _other)
{
	if (this != &_other)
	{
		m_bisSigned = _other.m_bisSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED
		<< m_name << " the Form got destroyed"
		<< RESET << std::endl;
}

std::string AForm::getName(void) const
{
	return (m_name);
}

bool AForm::getIsSigned(void) const
{
	return (m_bisSigned);
}

int AForm::getSignRequirement(void) const
{
	return (m_signRequirement);
}

int AForm::getExecRequirement(void) const
{
	return (m_execRequirement);
}

void AForm::beSigned(const Bureaucrat &_bureaucrat)
{
	if (_bureaucrat.getGrade() <= m_signRequirement)
	{
		m_bisSigned = true;
		std::cout << BRIGHT_GREEN
			<< _bureaucrat.getName()
			<< " signed " << m_name
			<< RESET << std::endl;
	}
	else
		throw (AForm::GradeTooLowException("Bureaucrat's grade is too low !"));
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!m_bisSigned)
		throw (AForm::NotSignedException("the form need to be signed first !"));
	if (executor.getGrade() > m_execRequirement)
		throw (AForm::GradeTooLowException("executor grade is too low !"));
	else
	{
		std::cout << BRIGHT_GREEN
			<< executor.getName() << " executed " << getName()
			<< RESET << std::endl;
		executeAction();
	}
}

AForm::GradeTooHighException::GradeTooHighException(const char *_msg)
	: m_message(_msg) {}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (m_message.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const char *_msg)
	: m_message(_msg) {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (m_message.c_str());
}

AForm::NotSignedException::NotSignedException(const char *_msg)
: m_message(_msg) {}

AForm::NotSignedException::~NotSignedException() throw() {}

const char *AForm::NotSignedException::what() const throw()
{
	return (m_message.c_str());
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm " << AForm.getName() << " :" << std::endl;
	os << " _Is Signed : " << AForm.getIsSigned() << std::endl;
	os << " _Sign Requirement : " << AForm.getSignRequirement() << std::endl;
	os << " _Exec Requirement : " << AForm.getExecRequirement() << std::endl;
	return (os);
}
