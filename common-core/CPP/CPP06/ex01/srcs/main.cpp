#include "Colors.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.id = 42;
	data.content = "Exercise 01: Serialization";

	std::cout << GREEN << "Original pointer: " << &data << std::endl;
	std::cout << BRIGHT_GREEN << "Data content:" << std::endl;
	std::cout << BRIGHT_GREEN << "ID: " << data.id << std::endl;
	std::cout << BRIGHT_GREEN << "Content: " << data.content << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << CYAN << "Serialized to uintptr_t: " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << GREEN << "Deserialized pointer: " << ptr << std::endl;

	std::cout << BRIGHT_GREEN << "Deserialized Data content:" << std::endl;
	std::cout << BRIGHT_GREEN << "ID: " << ptr->id << std::endl;
	std::cout << BRIGHT_GREEN << "Content: " << ptr->content << std::endl;

	if (ptr == &data)
		std::cout << GREEN
			<< "✅ Pointers match — Serialization successful!"
			<< RESET << std::endl;
	else
		std::cout << RED
			<< "❌ Pointers don't match!"
			<< RESET << std::endl;

	return (0);
}
