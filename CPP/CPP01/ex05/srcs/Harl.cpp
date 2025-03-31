#include "Harl.hpp"
#include "Colors.hpp"

void Harl::debug(void)
{
	std::cout << BLUE << "[DEBUG]: " << RESET
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info(void)
{
	std::cout << GREEN << "[INFO]: " << RESET
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!"
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING]: " << RESET
		<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years!"
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
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == _level)
		{
			(this->*actions[i])();
			return ;
		}
	}
	std::cout << RED << "Unknown Harl Level" << std::endl;
}
