#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <exception>

class Intern
{
  private:
  public:
    Intern();
    Intern(const Intern &orig);
    Intern &operator=(const Intern &orig);
    ~Intern();

    AForm *makeForm(const std::string &name, const std::string &target) const;

    class DoesNotExistFormName : public std::exception
    {
        const char *what(void) const throw();
    };
};

#endif
