#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal
{
	public:
	AAnimal();
	AAnimal(std::string _name);
	AAnimal(std::string _name, std::string _type);
	AAnimal(const AAnimal& _other);
	AAnimal& operator=(const AAnimal& _other);
	virtual ~AAnimal();

	virtual void	makeSound(void) const = 0;
	std::string		getType() const;
	std::string		getName() const;
	void			whoAmI() const;

	protected:
	std::string m_type;
	std::string m_name;
};

#endif
