#include "Bureaucrat.hpp"
#include "Form.hpp"

const std::string Bureaucrat::default_name = "default";

Bureaucrat::Bureaucrat() : _name(default_name), _grade(default_grade)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (_grade < highest_grade)
        throw(GradeTooHighException());
    if (_grade > lowest_grade)
        throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig) : _name(orig.getName()), _grade(orig.getGrade())
{
    if (_grade < highest_grade)
        throw(GradeTooHighException());
    if (_grade > lowest_grade)
        throw(GradeTooLowException());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &orig)
{
    if (this != &orig)
    {
        _name = orig.getName();
        _grade = orig.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < highest_grade)
        throw(GradeTooHighException());
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 < lowest_grade)
        throw(GradeTooLowException());
    _grade++;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << _name << " couldn’t sign " << form.getName() << "because" << e.what() << '\n';
    }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat: GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat: GradeTooLowException");
}
