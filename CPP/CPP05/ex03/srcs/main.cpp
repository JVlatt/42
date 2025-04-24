#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	srand(time(NULL));

	Intern intern;
	Bureaucrat boss(1, "Big Boss");

	AForm* shrubberform = intern.makeForm("shrubbery creation", "Home");
	AForm* robotform = intern.makeForm("robotomy request", "Bender");
	AForm* presidentform = intern.makeForm("presidential pardon", "Felon");
	AForm* badForm = intern.makeForm("unknown request", "Nobody");
	(void) badForm;
	
	boss.signForm(*shrubberform);
	boss.signForm(*robotform);
	boss.signForm(*presidentform);

	boss.executeForm(*shrubberform);
	boss.executeForm(*robotform);
	boss.executeForm(*presidentform);

	delete shrubberform;
	delete robotform;
	delete presidentform;

	return 0;
}
