#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));

	Bureaucrat high(1, "Boss");
	Bureaucrat mid(45, "Mid");
	Bureaucrat low(140, "Noob");

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Felon");

	std::cout << "\n--- Testing ShrubberyCreationForm ---" << std::endl;
	low.signForm(shrub);	 // Should work
	low.executeForm(shrub);	 // Should fail (exec grade too low)
	high.executeForm(shrub); // Should succeed

	std::cout << "\n--- Testing RobotomyRequestForm ---" << std::endl;
	low.signForm(robot);	  // Should fail
	mid.signForm(robot);	// Should succeed
	mid.executeForm(robot); // Should succeed with 50% chance
	mid.executeForm(robot); // Run twice to see both outcomes

	std::cout << "\n--- Testing PresidentialPardonForm ---" << std::endl;
	low.signForm(pardon);	  // Should fail
	mid.signForm(pardon);	  // Should fail
	high.signForm(pardon);	  // Should succeed
	high.executeForm(pardon); // Should succeed
}
