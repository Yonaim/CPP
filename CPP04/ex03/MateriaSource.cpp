#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < memory_capacity; ++i)
	{
		_memory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < memory_capacity; ++i)
	{
		if (_memory[i] != NULL)
			delete _memory[i];			
	}
}

void MateriaSource::learnMateria(AMateria *to_study)
{
	if (to_study == NULL)
	{
		std::cout << "learnMateria failed: invalid input Materia" << std::endl;
		return;
	}
	for (size_t i = 0; i < memory_capacity; ++i)
	{
		if (_memory[i] == NULL)
		{
			_memory[i] = to_study;
			std::cout << "learnMateria succeed: leanred '"
					  << to_study->getType() << "'" << std::endl;
			return;
		}
	}
	std::cout << "learnMateria failed: memory is full" << std::endl;
	return;
}

void MateriaSource::eraseMateria(std::string const &type)
{
	for (size_t i = 0; i < memory_capacity; ++i)
	{
		if (_memory[i]->getType() == type)
		{
			delete _memory[i];
			_memory[i] = NULL;
			std::cout << "eraseMateria succeed: inventory #" << i << " deleted"
					  << std::endl;
			return;
		}
	}
	std::cout << "eraseMateria failed: input type not found in current source"
			  << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < memory_capacity; ++i)
	{
		if (_memory[i] && _memory[i]->getType() == type)
		{
			std::cout << "createMateria succeed: '" << type << "'" << std::endl;
			return (_memory[i]->clone());
		}
	}
	std::cout << "createMateria failed: input type not found in current source"
			  << std::endl;
	return (0);
}
