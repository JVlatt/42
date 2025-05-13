#include <sstream>
#include <cstdlib>

#include "Colors.hpp"
#include "RPN.hpp"

static void execOperation(std::stack<int, std::list<int> > _slist, char _operand)
{
	int result = _slist.top();
	_slist.pop();
	std::cout << result << _operand << _slist.top() << std::endl;
	switch (_operand)
	{
	case '-':
		result -= _slist.top();
		break;
	case '+':
		result += _slist.top();
		break;
	case '*':
		result *= _slist.top();
		break;
	case '/':
		result /= _slist.top();
		break;
	default:
		break;
	}
	_slist.pop();
	_slist.push(result);
}

void parse_input(char *_input)
{
	std::stack<int, std::list<int> > s_list;
	std::stringstream sstream(_input);
	std::string element;

	while (std::getline(sstream, element, ' '))
	{
		if (element.length() != 1)
		{
			std::cout << RED
				<< "Error"
				<< RESET << std::endl;
		}
		if (element[0] >= '0' && element[0] <= '9')
		{
			s_list.push(std::atoi(element.c_str()));
		}
		else if (s_list.size() > 1 && (element[0] == '*' || element[0] == '+' || element[0] == '-' || element[0] == '/'))
		{
			execOperation(s_list, element[0]);
		}
		else
		{
			std::cout << RED
				<< "Error : " << element
				<< RESET << std::endl;
		}
	}
	if (s_list.size() != 1)
	{
		std::cout << RED
			<< "Error"
			<< RESET << std::endl;
		while (s_list.size() != 1)
		{
			std::cout << s_list.top() << std::endl;
			s_list.pop();
		}
	}
	else
		std::cout << GREEN
			<< s_list.top()
			<< RESET << std::endl;
}
