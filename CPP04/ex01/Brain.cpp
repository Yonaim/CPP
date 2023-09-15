#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "A Brain object has been created" << std::endl;
}

Brain::Brain(const Brain &orig)
{
	for (size_t i = 0; i < _n_ideas; ++i)
		_ideas[i] = orig._ideas[i];	
}

Brain &Brain::operator=(const Brain &orig)
{
	for (size_t i = 0; i < _n_ideas; ++i)
		_ideas[i] = orig._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "A Brain object has been deleted" << std::endl;
}

const std::string &Brain::getIdea(const int idx) const
{
	return (_ideas[idx]);
}

void Brain::setIdea(const int idx, const std::string str)
{
	_ideas[idx] = str;
}
