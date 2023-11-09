#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", required_grades_sign, required_grades_exec)
{
    setTarget("");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", required_grades_sign, required_grades_exec)
{
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig) : AForm(orig)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &orig)
{
    AForm::operator=(orig);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkExecutable(executor);
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
