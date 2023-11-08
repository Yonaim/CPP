#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", required_grades_sign, required_grades_exec)
{
	setType("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, required_grades_sign, required_grades_exec)
{
	setType("PresidentialPardonForm");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig) : AForm(orig)
{
	setType("PresidentialPardonForm");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &orig)
{
    // 1. AForm의 복사 할당 연산자를 이용해 AForm 타입 객체를 얻음
    // 2. 안전한 down 캐스팅을 위해 다이나믹 캐스팅 사용
 	return *(dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(orig))));
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
