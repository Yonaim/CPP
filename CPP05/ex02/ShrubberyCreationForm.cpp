#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig) : AForm(orig)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig)
{
    (void)orig;
    // TODO: AForm의 복사 할당 연산자를 사용해 구현
    // 1. AForm의 복사 할당 연산자를 이용해 AForm 타입 객체를 얻음
    // 2. 안전한 down 캐스팅을 위해 다이나믹 캐스팅 사용
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecutable(executor);
    // TODO: 파일 생성 후 아스키 트리 작성하는 부분 추가
}
