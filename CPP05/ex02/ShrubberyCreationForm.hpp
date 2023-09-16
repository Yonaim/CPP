#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
  private:
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &orig);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &orig);
    virtual ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const &executor) const;

};

#endif
