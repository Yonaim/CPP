#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
  private:
  public:
    static const int required_grades_sign = 25;
    static const int required_grades_exec = 5;

    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &orig);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &orig);
    virtual ~PresidentialPardonForm();

    virtual void execute(Bureaucrat const &executor) const;
};

#endif
