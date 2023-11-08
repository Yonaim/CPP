#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// srand(time(0));
    try
    {
        Bureaucrat ok_exec("ok_exec", ShrubberyCreationForm::required_grades_exec);
        Bureaucrat ok_sign("ok_sign", ShrubberyCreationForm::required_grades_sign);
        Bureaucrat no_exec("no_exec", ShrubberyCreationForm::required_grades_exec + 1);
        Bureaucrat no_sign("no_sign", ShrubberyCreationForm::required_grades_sign + 1);

        ShrubberyCreationForm sform("home");

        sform.beSigned(ok_sign);
        // sform.beSigned(no_sign);
        sform.execute(ok_exec);
        // sform.execute(no_exec);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    try
    {
        Bureaucrat ok_exec("ok_exec", RobotomyRequestForm::required_grades_exec);
        Bureaucrat ok_sign("ok_sign", RobotomyRequestForm::required_grades_sign);
        Bureaucrat no_exec("no_exec", RobotomyRequestForm::required_grades_exec + 1);
        Bureaucrat no_sign("no_sign", RobotomyRequestForm::required_grades_sign + 1);

        RobotomyRequestForm rform("robot");

        rform.beSigned(ok_sign);
        // rform.beSigned(no_sign);
    	srand(time(0));
        rform.execute(ok_exec);
        rform.execute(ok_exec);
        rform.execute(ok_exec);
        rform.execute(ok_exec);
        rform.execute(ok_exec);
        // rform.execute(no_exec);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    try
    {
        Bureaucrat ok_exec("ok_exec", PresidentialPardonForm::required_grades_exec);
        Bureaucrat ok_sign("ok_sign", PresidentialPardonForm::required_grades_sign);
        Bureaucrat no_exec("no_exec", PresidentialPardonForm::required_grades_exec + 1);
        Bureaucrat no_sign("no_sign", PresidentialPardonForm::required_grades_sign + 1);

        PresidentialPardonForm pform("president");

        pform.beSigned(ok_sign);
        // pform.beSigned(no_sign);
        pform.execute(ok_exec);
        // pform.execute(no_exec);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

    try
    {
        Bureaucrat master("master", 1);
        ShrubberyCreationForm sform("sform");
        
        sform.beSigned(master);
        master.executeForm(sform);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Catched in main function" << std::endl;
        // executeForm 함수의 에러는 메인 함수에서 캐치되지 않는다
    }
    return (0);
}
