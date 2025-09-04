#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	WrongCat(std::string _name);
	WrongCat(const WrongCat& _other);
	WrongCat& operator=(const WrongCat& _other);
	~WrongCat();

	void makeSound() const;
};

#endif
