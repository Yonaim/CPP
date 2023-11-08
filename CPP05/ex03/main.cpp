#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm *f1, *f2, *f3, *f4;

		f1 = someRandomIntern.makeForm("robotomy request", "target1");
		f2 = someRandomIntern.makeForm("shrubbery creation", "target2");
		f3 = someRandomIntern.makeForm("presidential pardon", "target3");
		f4 = someRandomIntern.makeForm("wrong type", "target4");
		delete f1;
		delete f2;
		delete f3;
		delete f4;
	}
    return (0);
}
