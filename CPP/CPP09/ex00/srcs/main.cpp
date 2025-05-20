#include "Colors.hpp"
#include "Utils.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Use './btc <input>'" << std::endl;
		return (1);
	}
	std::map<std::string, float> data_map;
	try
	{
		data_map = parse_data();
		parse_input(data_map, argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout <<
			RED << e.what()
			<< RESET << std::endl;
	}
	return (0);
}
