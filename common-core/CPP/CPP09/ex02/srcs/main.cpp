#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <algorithm>
#include <iomanip>

#include "Colors.hpp"
#include "PmergeMe.hpp"


static int checker(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

static int ft_atoi(char const *str)
{
	int result = 0;
	bool negate;

	if (str == NULL || *str == '\0')
		throw std::invalid_argument("null or empty string argument");
	while (std::isspace(*str))
		++str;
	negate = (*str == '-');
	if (*str == '+' || *str == '-')
		++str;
	if (*str == '\0')
		throw std::invalid_argument("sign character only.");
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			while (std::isspace(*str))
				++str;
			if (*str)
				throw std::invalid_argument("invalid input string");
			else
				break;
		}
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && *str - '0' > INT_MAX % 10))
			throw std::overflow_error("overflow occurred");
		if (result < INT_MIN / 10 || (result == INT_MIN / 10 && *str - '0' > -(INT_MIN % 10)))
			throw std::overflow_error("underflow occurred");
		result = result * 10 + (*str - '0');
		++str;
	}
	return negate ? -result : result;
}

std::vector<int> parse_input(int argc, char **argv)
{
	std::vector<int> parsev;
	std::stringstream input_stream;

	for (int i = 1; i < argc; i++)
	{
		input_stream << argv[i] << " ";
	}

	std::string element;
	while(getline(input_stream, element, ' '))
	{
		int value;
		try
		{
			value = ft_atoi(element.c_str());
		}
		catch(const std::exception& e)
		{
			std::string error  = "Conversion error: ";
			throw (std::invalid_argument(error.append(e.what())));
		}
		if (value < 0)
		throw (std::invalid_argument("Cannot use negative values"));
		else if (std::find(parsev.begin(),parsev.end(), value) != parsev.end())
		throw (std::invalid_argument("Only use unique values"));
		else
		parsev.push_back(value);
	}
	if (parsev.size() < 2)
	throw (std::invalid_argument("Use at least 2 values"));
	else if (is_sorted(parsev))
	throw (std::invalid_argument("Values are already sorted"));
	return (parsev);
}

int main(int argc, char **argv)
{
	std::vector<int> input;
	try
	{
		input = parse_input(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cout << RED
		<< "Parsing Error: "
		<<e.what()
		<< RESET << std::endl;
		return (0);
	}

	std::cout << " === DEQUE ===" << std::endl;
	std::cout << "Before : ";
	printArray(input, 1, false);

	PmergeMe::nbr_of_comps = 0;

	clock_t start_time = clock();
	std::deque<int> _outputd = ft_sort_deque(input);
	clock_t end_time = clock();
	std::cout << "After : ";
	printArray(_outputd, 1, false);
	std::cout << "Number of Comparison : " << PmergeMe::nbr_of_comps << std::endl;
	std::cout << "Max Number of Comparison : " << checker(input.size()) << std::endl;
	std::cout << "Time to process a range of "
		<< _outputd.size() << " elements with std::deque : "
		<<(((double) (end_time - start_time)) / (CLOCKS_PER_SEC / 1000000))
		<< " us" << std::endl;

	std::cout << " === VECTOR ===" << std::endl;
	PmergeMe::nbr_of_comps = 0;

	std::cout << "Before : ";
	printArray(input, 1, false);

	start_time = clock();
	std::vector<int> _outputv = ft_sort_vec(input);
	end_time = clock();
	std::cout << "After : ";
	printArray(_outputv, 1, false);
	std::cout << "Number of Comparison : " << PmergeMe::nbr_of_comps << std::endl;
	std::cout << "Max Number of Comparison : " << checker(input.size()) << std::endl;
	std::cout << "Time to process a range of "
		<< _outputv.size() << " elements with std::vector : "
		<<(((double) (end_time - start_time)) / (CLOCKS_PER_SEC / 1000000) )
		<< " us" << std::endl;

	std::cout << std::endl;
	return (0);
}
