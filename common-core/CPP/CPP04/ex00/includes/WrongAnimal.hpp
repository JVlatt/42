#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
	WrongAnimal();
	WrongAnimal(std::string _name);
	WrongAnimal(std::string _name, std::string _type);
	WrongAnimal(const WrongAnimal& _other);
	WrongAnimal& operator=(const WrongAnimal& _other);
	virtual ~WrongAnimal();

	void	makeSound(void) const;
	std::string		getType() const;
	std::string		getName() const;
	void			whoAmI() const;

	protected:
	std::string m_type;
	std::string m_name;
private:

};

#endif
