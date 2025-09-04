#include "UserNavigation.hpp"

int	main()
{
	PhoneBook myPhoneBook;

	system("clear");
	std::cout << CYAN << "Welcome to my Awesome PhoneBook !" << std::endl;
	selectAction(myPhoneBook);
	return (0);
}
