#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", required_grades_sign, required_grades_exec)
{
    setTarget("");
    setType("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("default", required_grades_sign, required_grades_exec)
{
    setTarget(target);
    setType("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig) : AForm(orig)
{
    setType("PresidentialPardonForm");
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
