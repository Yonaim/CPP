#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", required_grades_sign, required_grades_exec)
{
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, required_grades_sign, required_grades_exec)
{
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig) : AForm(orig)
{
	setType("ShrubberyCreationForm");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig)
{
    // 1. AForm의 복사 할당 연산자를 이용해 AForm 타입 객체를 얻음
    // 2. 안전한 down 캐스팅을 위해 다이나믹 캐스팅 사용
 	return *(dynamic_cast<ShrubberyCreationForm*>(&(AForm::operator=(orig))));
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char *ShrubberyCreationForm::FileOpenFailedExeption::what(void) const throw()
{
	return ("File Open Failed");
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecutable(executor);
    const std::string ascii_trees = \
      "               ,@@@@@@@,\n"
      "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
      "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
      "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
      "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
      "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
      "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
      "       |o|        | |         | |\n"
      "       |.|        | |         | |\n"
	  "    \\\\/ ._\\//_ /__/ ,\\_//__\\ /.  \\_//__/_";
    std::ofstream outfile(getTarget() + "_shrubbery", \
						std::ofstream::out | std::ofstream::trunc);
	if (!outfile.good())
		throw (FileOpenFailedExeption());
	outfile << ascii_trees;
	outfile.close();
}
