#include "Colors.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat op = Bureaucrat(0, "goat");
		Bureaucrat low = Bureaucrat(151, "low");
		Bureaucrat ok = Bureaucrat(75, "ok");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
