#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        Intern someRandomIntern;
        AForm *f1, *f2, *f3, *f4;

        f1 = someRandomIntern.makeForm("shrubbery creation", "target1");
        f2 = someRandomIntern.makeForm("robotomy request", "target2");
        f3 = someRandomIntern.makeForm("presidential pardon", "target3");
        f4 = someRandomIntern.makeForm("Not exist type", "target4");

        std::cout << "---------------------------" << std::endl;

        Bureaucrat someBure("someBure", 1);

        someBure.signForm(*f1);
        someBure.executeForm(*f1);

        someBure.signForm(*f2);
        someBure.executeForm(*f2);

        someBure.signForm(*f3);
        someBure.executeForm(*f3);

        delete f1;
        delete f2;
        delete f3;
        delete f4;
    }
    return (0);
}
