#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
  public:
	static const size_t memory_capacity = 4;

	MateriaSource();
	~MateriaSource();

	virtual void learnMateria(AMateria *);
	virtual void eraseMateria(std::string const &type);
	virtual AMateria *createMateria(std::string const &type);

  private:
	AMateria *_memory[memory_capacity];
};
