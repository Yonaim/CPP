#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", required_grades_sign, required_grades_exec)
{
    setTarget("");
    setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("default", required_grades_sign, required_grades_exec)
{
    setTarget(target);
    setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig) : AForm(orig)
{
    setType("RobotomyRequestForm");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &orig)
{
    AForm::operator=(orig);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecutable(executor);
    std::cout << "*some drilling noise*" << std::endl;
    int n = rand() % 100; // range 0 to 99
    // std::cout << "number: " << n << std::endl;
    if (n < 50)
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->getTarget() << " has been robotomized failed" << std::endl;
}
