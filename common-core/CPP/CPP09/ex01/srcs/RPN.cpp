#include <sstream>
#include <cstdlib>

#include "Colors.hpp"
#include "RPN.hpp"

static int execOperation(std::stack<int, std::list<int> > _slist, char _operand)
{
	int b = _slist.top();
	_slist.pop();
	int a = _slist.top();
	_slist.pop();
	switch (_operand)
	{
	case '-':
		return (a - b);
		break;
	case '+':
		return (a + b);
		break;
	case '*':
		return (a * b);
		break;
	case '/':
		if (b == 0)
			throw (std::runtime_error("Error: Attempted to divide by zero"));
		return (a / b);
		break;
	default:
		break;
	}
	return (-1);
}

void parse_input(char *_input)
{
	std::stack<int, std::list<int> > s_list;
	std::stringstream sstream(_input);
	std::string element;
	int operations = 0;

	while (std::getline(sstream, element, ' '))
	{
		int i = 0;
		if (element.length() > 2)
		{
			std::cout << RED
				<< "Error: invalid argument"
				<< RESET << std::endl;
			return ;
		}
		if (element.length() == 2) // sign + number
		{
			if (element[0] == '-' || element[0] == '+')
				i = 1;
			else
			{
				std::cout << RED
					<< "Error: invalid argument"
					<< RESET << std::endl;
				return ;
			}
		}
		if (element[0 + i] >= '0' && element[0 + i] <= '9')
		{
			s_list.push(std::atoi(element.c_str()));
		}
		else if (s_list.size() > 1 && (element[0] == '*' || element[0] == '+' || element[0] == '-' || element[0] == '/'))
		{
			int result = 0;
			try
			{
				result = execOperation(s_list, element[0]);
			}
			catch(std::exception &e)
			{
				std::cout << RED
					<< e.what()
					<< RESET << std::endl;
				return ;
			}
			s_list.pop();
			s_list.pop();
			s_list.push(result);
			operations ++;
		}
		else
		{
			std::cout << RED
				<< "Error: invalid argument"
				<< RESET << std::endl;
			return ;
		}
	}
	if (s_list.size() != 1 || operations < 1)
	{
		std::cout << RED
			<< "Error: more than 1 element in stack"
			<< RESET << std::endl;
		return ;
	}
	else
		std::cout << GREEN
			<< s_list.top()
			<< " (" << operations << " operations)"
			<< RESET << std::endl;
}
