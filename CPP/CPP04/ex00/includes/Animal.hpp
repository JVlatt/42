#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{

	public:
	Animal();
	Animal(std::string _name);
	Animal(std::string _name, std::string _type);
	Animal(const Animal& _other);
	Animal& operator=(const Animal& _other);
	virtual ~Animal();

	virtual void	makeSound(void) const;
	std::string		getType() const;
	std::string		getName() const;
	void			whoAmI() const;

	protected:
	std::string m_type;
	std::string m_name;
};

#endif
