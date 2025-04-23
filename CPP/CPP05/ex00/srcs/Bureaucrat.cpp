#include "Bureaucrat.hpp"
#include "Colors.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << GREEN
		<< "A New Bureaucrat got hired"
		<< RESET << std::endl;
	m_grade = 150;
}

Bureaucrat::Bureaucrat(int _grade, std::string _name) : m_name(_name)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high : Grade must be within 1-150 range !");
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low : Grade must be within 1-150 range !");
	m_grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& _other)
{
	*this = _other;
}

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
