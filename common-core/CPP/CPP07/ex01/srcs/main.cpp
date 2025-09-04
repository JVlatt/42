#include "Colors.hpp"
#include "iter.hpp"

struct Data
{
	int id;
	std::string content;
};

static void printData(const Data &d)
{
	std::cout << d.id << " : " << d.content << std::endl;
}

static void minimizeData(Data &d)
{
	d.content = 97 + d.id;
}

static void pow(int &i)
{
	i *= i;
}

static void printi(const int &i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int int_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Data data_array[10];

	for (int i = 0; i < 10 ;++i)
	{
		data_array[i].id = i;
		data_array[i].content = 65 + i;
	}

	std::cout << "Int Array : " << std::endl;
	std::cout << "\nBefore : " << std::endl;
	iter(int_array, 10, printi);
	iter(int_array, 10, pow);
	std::cout << "\nAfter : " << std::endl;
	iter(int_array, 10, printi);

	std::cout << "\nData Array : " << std::endl;
	std::cout << "\nBefore : " << std::endl;
	iter(data_array, 10, printData);
	iter(data_array, 10, minimizeData);
	std::cout << "\nAfter : " << std::endl;
	iter(data_array, 10, printData);

	return 0;
}

