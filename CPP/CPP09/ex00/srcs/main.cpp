#include "Colors.hpp"
#include "parsing.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Use './btc <input>'" << std::endl;
		return (1);
	}

	std::map<std::string, float> data_map = parse_data();
	parse_input(data_map, argv[1]);
	return (0);
}
