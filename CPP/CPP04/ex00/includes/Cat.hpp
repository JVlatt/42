#ifndef CAT_HPP
#define CAT_HPP

#include <string>

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(std::string _name);
	Cat(const Cat& _other);
	Cat& operator=(const Cat& _other);
	~Cat();

	void makeSound() const;
};

#endif
