#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
  private:
  public:
    static const int required_grades_sign = 72;
    static const int required_grades_exec = 45;

    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &orig);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &orig);
    virtual ~RobotomyRequestForm();

    virtual void execute(Bureaucrat const &executor) const;
};

#endif
