#include "Form.hpp"
#include "Colors.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: m_name("Default"), m_bisSigned(false), m_signRequirement(50), m_execRequirement(10)
{
	std::cout << GREEN
		<< "A New Form got printed !\n"
		<< *this
		<< RESET << std::endl;
}

Form::Form(std::string _name, bool _isSigned, const int _signRequirement, const int _execRequirement)
	: m_name(_name), m_bisSigned(_isSigned),
	m_signRequirement(_signRequirement), m_execRequirement(_execRequirement)
{
	if (_signRequirement < 1)
		throw Form::GradeTooHighException("Sign Grade too high : Grade must be within 1-150 range !");
	else if (_signRequirement > 150)
		throw Form::GradeTooLowException("Sign Grade too low : Grade must be within 1-150 range !");
	if (_execRequirement < 1)
		throw Form::GradeTooHighException("Exec Grade too high : Grade must be within 1-150 range !");
	else if (_execRequirement > 150)
		throw Form::GradeTooLowException("Exec Grade too low : Grade must be within 1-150 range !");
	std::cout << GREEN
		<< "A New Form got printed !\n"
		<< *this
		<< RESET << std::endl;
}

Form::Form(const Form& _other)
	: m_name(_other.m_name), m_bisSigned(_other.m_bisSigned),
	m_signRequirement(_other.m_signRequirement), m_execRequirement(_other.m_execRequirement) {}

Form& Form::operator=(const Form& _other)
{
	if (this != &_other)
	{
		m_bisSigned = _other.m_bisSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << RED
		<< m_name << " the Form got destroyed"
		<< RESET << std::endl;
}

std::string Form::getName(void) const
{
	return (m_name);
}

bool Form::getIsSigned(void) const
{
	return (m_bisSigned);
}

int Form::getSignRequirement(void) const
{
	return (m_signRequirement);
}

int Form::getExecRequirement(void) const
{
	return (m_execRequirement);
}

void Form::beSigned(const Bureaucrat &_bureaucrat)
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
		throw (Form::GradeTooLowException("Bureaucrat's grade is too low !"));
}

Form::GradeTooHighException::GradeTooHighException(const char *_msg)
	: m_message(_msg) {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what() const throw()
{
	return (m_message.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const char *_msg)
	: m_message(_msg) {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what() const throw()
{
	return (m_message.c_str());
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
	os << "Form " << Form.getName() << " :" << std::endl;
	os << " _Is Signed : " << Form.getIsSigned() << std::endl;
	os << " _Sign Requirement : " << Form.getSignRequirement() << std::endl;
	os << " _Exec Requirement : " << Form.getExecRequirement() << std::endl;
	return (os);
}
