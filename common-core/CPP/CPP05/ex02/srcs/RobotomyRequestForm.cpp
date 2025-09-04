#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << GREEN
		<< "A New RobotomyForm got printed !\n"
		<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
:	AForm("Robotomy", false, 72, 45), m_target(_target)
{
	std::cout << GREEN
		<< "A New RobotomyForm which target "
		<< m_target << " got printed !\n"
		<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _other)
:	AForm(_other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& _other)
{
	if (this != &_other)
	{
		m_target = _other.m_target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED
		<< getName() << " the RobotomyForm got destroyed"
		<< RESET << std::endl;
}

void RobotomyRequestForm::executeAction() const
{

	std::cout << CYAN
		<< "*drilling noises*"
		<< RESET << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << BRIGHT_GREEN
			<< "Robotomy Successfull !"
			<< RESET << std::endl;
	}
	else
	{
		std::cout << BRIGHT_RED
			<< "Robotomy Failed !"
			<< RESET << std::endl;
	}
}
