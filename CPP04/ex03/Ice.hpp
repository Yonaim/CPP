#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

// Materias concrete classes Ice

class Ice : public AMateria
{
  public:
	Ice();
	Ice(const Ice &orig);
	Ice &operator=(const Ice &orig);
	virtual ~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif
