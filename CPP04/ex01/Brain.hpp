#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  private:
	static const size_t _n_ideas = 100;
	std::string _ideas[_n_ideas];

  public:
	Brain();
	Brain(const Brain &orig);
	Brain &operator=(const Brain &orig);
	~Brain();

	const std::string &getIdea(const int idx) const;
	void setIdea(const int idx, const std::string str);
};

#endif