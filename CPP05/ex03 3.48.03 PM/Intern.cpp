#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &orig)
{
}

Intern &Intern::operator=(const Intern &orig)
{
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string types[3] = {"shrubbery creation", 
								"robotomy request", 
								"presidential pardon"};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (name == types[i])
			{
				std::cout << "Intern creates " << name << std::endl;
				switch (i)
				{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
				default:
					break;
				}
			}
		}
		throw (DoesNotExistFormType());
	}
	catch(const std::exception& e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (NULL);
}

const char *Intern::DoesNotExistFormType::what(void) const throw()
{
	return ("Does not exist form type");
}
