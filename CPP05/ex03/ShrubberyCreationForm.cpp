#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", required_grades_sign, required_grades_exec)
{
    setTarget("");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", required_grades_sign, required_grades_exec)
{
    setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig) : AForm(orig)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig)
{
    AForm::operator=(orig);
    return (*this);
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
    const std::string ascii_trees = "               ,@@@@@@@,\n"
                                    "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                                    "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                                    "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                                    "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                                    "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                                    "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                                    "       |o|        | |         | |\n"
                                    "       |.|        | |         | |\n"
                                    "    \\\\/ ._\\//_ /__/ ,\\_//__\\ /.  \\_//__/_";
    std::ofstream outfile(getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
    if (!outfile.good())
        throw(FileOpenFailedExeption());
    outfile << ascii_trees;
    outfile.close();
}
