#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", required_grades_sign, required_grades_exec)
{
	setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, required_grades_sign, required_grades_exec)
{
	setType("RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig) : AForm(orig)
{
	setType("RobotomyRequestForm");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &orig)
{
    // 1. AForm의 복사 할당 연산자를 이용해 AForm 타입 객체를 얻음
    // 2. 안전한 down 캐스팅을 위해 다이나믹 캐스팅 사용
 	return *(dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(orig))));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecutable(executor);
	std::cout << "*some drilling noise*" << std::endl;
	srand(time(0));
	int n = rand() % 100; // range 0 to 99
	if (n < 50)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " has been robotomized failed" << std::endl;
}
