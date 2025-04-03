#include "UserNavigation.hpp"
#include "Utils.hpp"

static void	exitApp(PhoneBook _phoneBook)
{
	(void) _phoneBook;

	std::cout << GREEN
		<< "\nThank you for using my Awesome PhoneBook !"
		<< RESET << std::endl;
}

static void finalInput(PhoneBook _phoneBook, const char *choice,
			void (*yesfunc)(PhoneBook), void (*nofunc)(PhoneBook))
{
	std::string	finalInput;

	while (finalInput != "n" && finalInput != "Y")
	{
		std::cout << choice << " [Y/n] ";
		std::getline(std::cin, finalInput);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	if (finalInput == "Y")
	{
		system("clear");
		yesfunc(_phoneBook);
	}
	else
	{
		system("clear");
		nofunc(_phoneBook);
	}
}

static int	convertIndex(std::string str, int limit)
{
	int result = -1;

	try {
		result = ft_atoi(str.c_str());
	}
	catch (const std::invalid_argument &){
		return (-1);
	}
	catch (const std::overflow_error &){
		return (-1);
	}
	if (result < 0 || result >= limit)
		return (-1);
	return (result);
}

static std::string	formatString(std::string _stringToFormat)
{
	std::string output;

	if (_stringToFormat.length() > 10)
		output = _stringToFormat.substr(0,9) + ".";
	else
		output = _stringToFormat;
	return (output);
}

static void	printContact(Contact _contactToPrint)
{
	system("clear");
	std::cout << GREEN << "Contact Infos :" << std::endl;
	std::cout << YELLOW << "\t[] First Name : " << RESET <<_contactToPrint.firstName << std::endl;
	std::cout << YELLOW << "\t[] Last Name : " << RESET <<_contactToPrint.lastName << std::endl;
	std::cout << YELLOW << "\t[] Nick Name : " << RESET <<_contactToPrint.nickName << std::endl;
	std::cout << YELLOW << "\t[] Phone Number : " << RESET <<_contactToPrint.phoneNumber << std::endl;
	std::cout << YELLOW << "\t[] Darkest Secret : " << RESET <<_contactToPrint.darkestSecret << std::endl;
}

static bool printPhoneBook(PhoneBook _phoneBook)
{
	system("clear");
	std::cout << GREEN << "Your PhoneBook :" << RESET << std::endl;
	if (_phoneBook.GetContactsNb() == 0)
	{
		std::cout << RED << "Your PhoneBook is empty" << RESET << std::endl;
		return (false);
	}
	else
	{
		for (int i = 0; i < _phoneBook.GetContactsNb(); ++i)
		{
			std::cout << std::setw(10) << "[" << i << "]";
			std::cout << "|" << std::setw(10) << formatString(_phoneBook.contacts[i].firstName);
			std::cout << "|" << std::setw(10) << formatString(_phoneBook.contacts[i].lastName);
			std::cout << "|" << std::setw(10) << formatString(_phoneBook.contacts[i].nickName);
			std::cout << std::endl;
		}
	}
	return (true);
}

static void searchContact(PhoneBook _phoneBook)
{
	int	selectedIndex = -1;
	std::string indexStr;

	if (printPhoneBook(_phoneBook))
	{
		while (selectedIndex == -1)
		{
			std::cout << "Select Index to Display : ";
			std::getline(std::cin, indexStr);
			if(std::cin.eof() || std::cin.fail())
			{
				exitApp(_phoneBook);
				return ;
			}
			selectedIndex = convertIndex(indexStr, _phoneBook.GetContactsNb());
			if (selectedIndex == -1)
				std::cout << RED << "Invalid Index !" << RESET << std::endl;
		}
		printContact(_phoneBook.contacts[selectedIndex]);
		finalInput(_phoneBook, "Go back to your PhoneBook ?", searchContact, selectAction);
	}
	else
		finalInput(_phoneBook, "Go back to Menu ?", selectAction, exitApp);
}

static void	addContact(PhoneBook _phoneBook)
{
	Contact		newContact;

	system("clear");
	std::cout << GREEN << "New Contact Informations :" << std::endl;
	while (newContact.firstName.empty() || ft_strisspace(newContact.firstName))
	{
		std::cout << YELLOW << "\t[] First Name : " << RESET;
		std::getline(std::cin, newContact.firstName);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	while (newContact.lastName.empty() || ft_strisspace(newContact.lastName))
	{
		std::cout << YELLOW << "\t[] Last Name : " << RESET;
		std::getline(std::cin, newContact.lastName);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	while (newContact.nickName.empty() || ft_strisspace(newContact.nickName))
	{
		std::cout << YELLOW << "\t[] Nick Name : " << RESET;
		std::getline(std::cin, newContact.nickName);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	while (newContact.phoneNumber.empty() || ft_strisspace(newContact.phoneNumber))
	{
		std::cout << YELLOW << "\t[] Phone Number : " << RESET;
		std::getline(std::cin, newContact.phoneNumber);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	while (newContact.darkestSecret.empty() || ft_strisspace(newContact.darkestSecret))
	{
		std::cout << YELLOW << "\t[] Darkest Secret : " << RESET;
		std::getline(std::cin, newContact.darkestSecret);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	_phoneBook.AddContact(newContact);
	system("clear");
	std::cout << GREEN << "New Contact \""
		<< YELLOW << newContact.firstName
		<< GREEN << "\" added to PhoneBook !"
		<< RESET << std::endl;
	finalInput(_phoneBook, "Would you like to add another one ?", addContact, selectAction);
}

void	selectAction(PhoneBook _phoneBook)
{
	std::string query;

	std::cout << GREEN << "\nWhat can I assist you with ?" << std::endl;
	std::cout << YELLOW << " [ADD]" << std::endl;
	std::cout << YELLOW << " [SEARCH]" << std::endl;
	std::cout << YELLOW << " [EXIT]" << std::endl;
	while (query.empty())
	{
		std::cout << RESET << "> ";
		std::getline(std::cin,query);
		if(std::cin.eof() || std::cin.fail())
		{
			exitApp(_phoneBook);
			return ;
		}
	}
	if (query == "ADD")
		addContact(_phoneBook);
	else if (query == "SEARCH")
		searchContact(_phoneBook);
	else if (query == "EXIT")
		exitApp(_phoneBook);
	else
	{
		system("clear");
		std::cout << RED << "Unknown action please try again !" << std::endl;
		selectAction(_phoneBook);
	}
}
