#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << GREEN
		<< "A New ShrubberyForm got printed !\n"
		<< RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
:	AForm("Shrubbery", false, 145, 137), m_target(_target)
{
	std::cout << GREEN
		<< "A New ShrubberyForm which target "
		<< m_target << " got printed !\n"
		<< RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _other)
:	AForm(_other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& _other)
{
	if (this != &_other)
	{
		m_target = _other.m_target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED
		<< getName() << " the ShrubberyForm got destroyed"
		<< RESET << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((m_target + "_shrubbery").c_str()); // use c_str() for C++98 compatibility
	if (!file)
	{
		std::cout << "Failed to open file: " << m_target + "_shrubbery" << std::endl;
		return;
	}

	file << "                                                         .\n";
	file << "                                              .         ;  \n";
	file << "                 .              .              ;%     ;;   \n";
	file << "                   ,           ,                :;%  %;   \n";
	file << "                    :         ;                   :;%;'     .,   \n";
	file << "           ,.        %;     %;            ;        %;'    ,;\n";
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
	file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
	file << "                    `:%;.  :;bd%;          %;@%;'\n";
	file << "                      `@%:.  :;%.         ;@@%;'   \n";
	file << "                        `@%.  `;@%.      ;@@%;         \n";
	file << "                          `@%%. `@%%    ;@@%;        \n";
	file << "                            ;@%. :@%%  %@@%;       \n";
	file << "                              %@bd%%%bd%%:;     \n";
	file << "                                #@%%%%%:;;\n";
	file << "                                %@@%%%::;\n";
	file << "                                %@@@%(o);  . '         \n";
	file << "                                %@@@o%;:(.,'         \n";
	file << "                            `.. %@@@o%::;         \n";
	file << "                               `)@@@o%::;         \n";
	file << "                                %@@(o)::;        \n";
	file << "                               .%@@@@%::;         \n";
	file << "                               ;%@@@@%::;.          \n";
	file << "                              ;%@@@@%%:;;;. \n";
	file << "                          ...;%@@@@@%%:;;;;,..\n";

	file.close();
}
