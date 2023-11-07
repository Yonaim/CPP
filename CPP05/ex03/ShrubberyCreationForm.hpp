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
	static const int required_grades_sign = 145;
	static const int required_grades_exec = 137;

    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &orig);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &orig);
    virtual ~ShrubberyCreationForm();

    virtual void execute(Bureaucrat const &executor) const;
    class FileOpenFailedExeption : public std::exception
    {
        const char *what(void) const throw();
    };
};

#endif
