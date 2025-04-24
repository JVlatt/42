#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"

Bureaucrat::Bureaucrat()
	: m_name("Default"), m_grade(150)
{
	std::cout << GREEN
		<< "A New Bureaucrat got hired"
		<< RESET << std::endl;
}

Bureaucrat::Bureaucrat(int _grade, std::string _name)
	: m_name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high : Grade must be within 1-150 range !");
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low : Grade must be within 1-150 range !");
	m_grade = _grade;
	std::cout << GREEN
		<< "A New Bureaucrat got hired : "
		<< *this << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& _other)
	: m_name(_other.m_name), m_grade(_other.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& _other)
{
	if (this != &_other)
	{
		m_grade = _other.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED
		<< m_name << " the Bureaucrat got fired"
		<< RESET << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (m_name);
}

int Bureaucrat::getGrade(void) const
{
	return (m_grade);
}

void Bureaucrat::increment(void)
{
	if (m_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException("Can't promote Bureaucrat he/she is already at the top !");
	else
		m_grade -= 1;
}

void Bureaucrat::decrement(void)
{
	if (m_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException("Bureaucrat is already at the bottom...");
	else
		m_grade += 1;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *_msg)
	: m_message(_msg) {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (m_message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *_msg)
	: m_message(_msg) {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (m_message.c_str());
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

void Bureaucrat::signForm(Form& _form)
{
	if (_form.getIsSigned())
	{
		std::cout << BRIGHT_RED
			<< m_name << " couldn't sign "
			<< _form.getName()
			<< " because it is already signed !"
			<< RESET << std::endl;
		return ;
	}
	try
	{
		_form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << BRIGHT_RED
			<< m_name << " couldn't sign "
			<< _form.getName() << " because "
			<< e.what()
			<< RESET << std::endl;
	}

}
