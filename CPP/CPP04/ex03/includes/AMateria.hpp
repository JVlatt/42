#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
	std::string m_type;

	public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& _other);
	AMateria& operator=(const AMateria& _other);
	~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
