#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include "AForm.hpp"

class Intern
{
  private:
  public:
    Intern();
    Intern(const Intern &orig);
    Intern &operator=(const Intern &orig);
    ~Intern();

	AForm *makeForm(const std::string &name, const std::string &target);

	class DoesNotExistFormType : public std::exception
	{
		const char *what(void) const throw();
	};
};

#endif
