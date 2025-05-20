#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include "Utils.hpp"

std::map<std::string, float> parse_data()
{
	std::ifstream file("data.csv");
	if (!file)
		throw(std::invalid_argument("Failed to open data file"));

	std::map<std::string, float> data_map;
	std::string line;
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		std::string rate_str;
		std::string date;
		if (std::getline(stream, date, ',') && std::getline(stream, rate_str))
		{
			std::stringstream rateStream(rate_str);
			float rate;
			if (rateStream >> rate)
			{
				data_map[date] = rate;
			}
			else
			{
				std::cout << RED
						  << "Invalid rate on line: " << line
						  << RESET << std::endl;
			}
		}
		else
		{
			std::cout << RED
					  << "Invalid line format: " << line
					  << RESET << std::endl;
		}
	}
	return (data_map);
}

static bool check_day(int _year, int _month, int _day)
{
	int days[] = {31, 28, 31, 30, 31, 30,
				  31, 31, 30, 31, 30, 31};
	if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
		days[1] = 29;
	if (_day > days[_month])
		return (false);
	return (true);
}

static bool check_date_format(std::stringstream &_date_stream)
{
	std::string day_str;
	std::string month_str;
	std::string year_str;

	if (std::getline(_date_stream, year_str, '-') && std::getline(_date_stream, month_str, '-') && std::getline(_date_stream, day_str))
	{
		int day = 0;
		int month = 0;
		int year = 0;
		try
		{
			day = ft_atoi(day_str.c_str());
			month = ft_atoi(month_str.c_str());
			year = ft_atoi(year_str.c_str());
		}
		catch (std::exception &e)
		{
			return (false);
		}

		if (day < 1 || month < 1 || month > 12)
			return (false);
		return (check_day(year, month, day));
	}
	return (false);
}

static void find_data(std::map<std::string, float> _data, std::string _key, float _value)
{
	std::map<std::string, float>::iterator it = _data.lower_bound(_key);
	if (it == _data.end())
		--it;
	else if (it->first != _key)
	{
		if (it == _data.begin())
		{
			std::cout << RED
					  << "Error: no earlier date found for key: " << _key
					  << RESET << std::endl;
			return;
		}
		--it;
	}
	std::cout << it->first << " => " << _value << " = " << it->second * _value << std::endl;
}

void parse_input(std::map<std::string, float> _data, const char *_input)
{
	int line_count = 2;
	std::ifstream file(_input);
	if (!file)
	{
		throw(std::invalid_argument("Failed to open input file"));
	}

	std::string line;
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		std::string value_str;
		std::string date;
		if (std::getline(stream, date, '|') && std::getline(stream, value_str))
		{
			std::stringstream dateStream(date);
			std::stringstream valueStream(value_str);
			float value;
			if (check_date_format(dateStream))
			{
				try
				{
					value = ft_atof(value_str.c_str());
					if (value < 0)
						std::cout << RED
								  << "Error: not a positive number."
								  << value_str
								  << " (line " << line_count << ")"
								  << RESET << std::endl;
					else if (value > 1000)
						std::cout << RED
								  << "Error: too large a number."
								  << value_str
								  << " (line " << line_count << ")"
								  << RESET << std::endl;
					else
						find_data(_data, date, value);
				}
				catch (const std::exception &e)
				{
					std::cout << RED
							  << "Error: bad input value => " << value_str
							  << " (line " << line_count << ")"
							  << RESET << std::endl;
				}
			}
			else
			{
				std::cout << RED
						  << "Error: invalid date => " << date
						  << " (line " << line_count << ")"
						  << RESET << std::endl;
			}
		}
		else
		{
			std::cout << RED
				<< "Error: invalid line format => " << line
				<< " (line " << line_count << ")"
				<< RESET << std::endl;
		}
		line_count++;
	}
}
