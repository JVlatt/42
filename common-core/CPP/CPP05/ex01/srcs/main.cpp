#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"
#include <iostream>

int main()
{
	std::cout << "\n--- Testing Form creation with invalid grades ---" << std::endl;
	try
	{
		Form f1("InvalidHigh", false, 0, 10);
	}
	catch (const std::exception& e)
	{
		std::cout << BRIGHT_RED
			<< "Exception : " << e.what()
			<< RESET << std::endl;
	}
	try
	{
		Form f2("InvalidLow", false, 10, 151);
	}
	catch (const std::exception& e)
	{
		std::cout << BRIGHT_RED
			<< "Exception : " << e.what()
			<< RESET << std::endl;
	}

	std::cout << "\n--- Creating Bureaucrats and Forms ---" << std::endl;
	Bureaucrat b1(40, "Alice");
	Bureaucrat b2(140, "Bob");

	Form f3("FormA", false, 50, 20);
	Form f4("FormB", false, 130, 40);
	Form f5("FormC", false, 140, 40);
	Form f6("AlreadySignedForm", true, 140, 40);

	std::cout << "\n--- Bureaucrats attempting to sign forms ---" << std::endl;
	b1.signForm(f3); // should succeed
	b2.signForm(f3); // already signed but Bob can't sign anyway
	b2.signForm(f4); // should fail
	b1.signForm(f4); // should succeed
	b2.signForm(f5); // should succeed
	b1.signForm(f5); // already signed
	b1.signForm(f6); // already signed

	return 0;
}
