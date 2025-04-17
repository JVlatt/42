#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& _other);
	Cure& operator=(const Cure& _other);
	~Cure();

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif
