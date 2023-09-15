#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

// Materias concrete classes Cure

class Cure : public AMateria
{
  public:
	Cure();
	Cure(const Cure &orig);
	Cure &operator=(const Cure &orig);
	virtual ~Cure();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif
