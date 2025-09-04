#include "Colors.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n--- Testing constructor with invalid high grade ---" << std::endl;
	try
	{
		Bureaucrat b1(0, "TooHigh");
	}
	catch (const std::exception &e)
	{
		std::cout << BRIGHT_RED
			<< "Exception: " << e.what()
			<< RESET << std::endl;
	}

	std::cout << "\n--- Testing constructor with invalid low grade ---" << std::endl;
	try
	{
		Bureaucrat b2(151, "TooLow");
	}
	catch (const std::exception &e)
	{
		std::cout << BRIGHT_RED
			<< "Exception: " << e.what()
			<< RESET << std::endl;
	}

	std::cout << "\n--- Testing normal Bureaucrat and increment ---" << std::endl;
	try
	{
		Bureaucrat b3(2, "AlmostTop");
		std::cout << b3 << std::endl;
		b3.increment(); // should succeed
		std::cout << "After increment: " << b3 << std::endl;
		b3.increment(); // should throw
	}
	catch (const std::exception &e)
	{
		std::cout << BRIGHT_RED
			<< "Exception: " << e.what()
			<< RESET << std::endl;
	}

	std::cout << "\n--- Testing normal Bureaucrat and decrement ---" << std::endl;
	try
	{
		Bureaucrat b4(149, "AlmostBottom");
		std::cout << b4 << std::endl;
		b4.decrement(); // should succeed
		std::cout << "After decrement: " << b4 << std::endl;
		b4.decrement(); // should throw
	}
	catch (const std::exception &e)
	{
		std::cout << BRIGHT_RED
			<< "Exception: " << e.what()
			<< RESET << std::endl;
	}

	// std::cout << "\n--- Testing copy constructor and assignment ---" << std::endl;
	// try
	// {
	// 	Bureaucrat b5(42, "Original");
	// 	Bureaucrat b6 = b5; // copy constructor
	// 	Bureaucrat b7(100, "ToBeAssigned");
	// 	b7 = b5; // assignment

	// 	std::cout << b6.getName() << " (copied), grade: " << b6.getGrade() << std::endl;
	// 	std::cout << b7.getName() << " (assigned), grade: " << b7.getGrade() << std::endl;
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }

	// std::cout << "\n--- Done Testing ---" << std::endl;
	return 0;

}
