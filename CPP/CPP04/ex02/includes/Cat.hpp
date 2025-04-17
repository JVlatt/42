#ifndef CAT_HPP
#define CAT_HPP

#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
	Cat();
	Cat(std::string _name);
	Cat(const Cat& _other);
	Cat& operator=(const Cat& _other);
	~Cat();

	void makeSound() const;

	private:
	Brain	*m_brain;
};

#endif
