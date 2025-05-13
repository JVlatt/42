#include "BitcoinExchange.hpp"
#include "Colors.hpp"

std::map<std::string, float> parse_data()
{
	std::ifstream file("data.csv");
	if (!file)
		throw(std::invalid_argument("Failed to open file"));

	std::map<std::string, float> data_map;
	std::string line;
	std::getline(file, line); //skip first line
	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		std::string rate_str;
		std::string date;
		if(std::getline(stream, date, ',') && std::getline(stream, rate_str))
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

static bool check_day(int _year , int _month, int _day)
{
	int days[] = {	31, 28, 31, 30, 31, 30,
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

	if (std::getline(_date_stream, year_str, '-')
		&& std::getline(_date_stream, month_str, '-')
		&& std::getline(_date_stream, day_str))
	{
		std::stringstream day_stream(day_str);
		std::stringstream month_stream(month_str);
		std::stringstream year_stream(year_str);

		int day = 0;
		int month = 0;
		int year = 0;

		if (!(day_stream >> day) || !(month_stream >> month) || !(year_stream >> year))
			return (false);
		if (day < 1 || month < 1 || month > 12)
			return (false);
		return (check_day(year, month, day));
	}
	return (false);
}

static void find_data(std::map<std::string,float> _data, std::string _key, float _value)
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
			return ;
		}
		--it;
	}
	std::cout << it->first << " => " << _value << " = " << it->second * _value << std::endl;
}

void	parse_input(std::map<std::string,float> _data, const char *_input)
{
	int line_count = 2;
	std::ifstream file(_input);
	if (!file)
		throw(std::invalid_argument("Failed to open file"));

	std::string line;
	std::getline(file, line); //skip first line
	while (std::getline(file, line))
	{
		std::stringstream stream(line);
		std::string value_str;
		std::string date;
		if(std::getline(stream, date, '|') && std::getline(stream, value_str))
		{
			std::stringstream valueStream(value_str);
			std::stringstream dateStream(date);
			float value;
			if (check_date_format(dateStream))
			{
				if (valueStream >> value)
				{
					if (value < 0)
						std::cout << RED
							<< "Error: not a positive number."
							<< " (line " << line_count << ")"
							<< RESET << std::endl;
					else if (value > 1000)
						std::cout << RED
							<< "Error: too large a number."
							<< " (line " << line_count << ")"
							<< RESET << std::endl;
					else
						find_data(_data, date, value);
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
				<< "Error: bad input => " << line
				<< " (line " << line_count << ")"
				<< RESET << std::endl;
		}
		line_count++;
	}
}
