#include "Harl.hpp"
#include "Colors.hpp"

int	str_to_level(std::string _level)
{
	if (_level == "DEBUG")
		return (1);
	else if (_level == "INFO")
		return (2);
	else if (_level == "WARNING")
		return (3);
	else if (_level == "ERROR")
		return (4);
	return (-1);
}

void Harl::debug(void)
{
	std::cout << BLUE << "[DEBUG]: " << RESET
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info(void)
{
	std::cout << GREEN << "[INFO]: " << RESET
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!"
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING]: " << RESET
		<< "I think I deserve to have some extra bacon for free. I've been coming here for years!"
		<< std::endl;
}

void Harl::error(void)
{
	std::cout << RED << "[ERROR]: " << RESET
		<< "This is unacceptable! I want to speak to the manager now!"
		<< std::endl;
}

void Harl::complain(std::string _level)
{
	switch(str_to_level(_level))
	{
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
			break;
		default:
			std::cout << CYAN
			<< "[ Probably complaining about insignificant problems ]"
			<< RESET <<std::endl;
	}
}
