#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _grade_to_sign(100), _grade_to_exec(100)
{
}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_exec)
    : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
}

AForm::AForm(const AForm &orig)
    : _name(orig.getName()), _is_signed(orig.getIsSigned()), _grade_to_sign(orig.getGradeRequiredToSign()),
      _grade_to_exec(orig.getGradeRequiredToExecute())
{
}

AForm &AForm::operator=(const AForm &orig)
{
    if (this != &orig)
    {
        *(const_cast<std::string *>(&_name)) = orig.getName();
        _is_signed = orig.getIsSigned();
        *(const_cast<int *>(&_grade_to_sign)) = orig.getGradeRequiredToSign();
        *(const_cast<int *>(&_grade_to_exec)) = orig.getGradeRequiredToExecute();
    }
    return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName(void) const
{
    return (_name);
}

bool AForm::getIsSigned(void) const
{
    return (_is_signed);
}

int AForm::getGradeRequiredToSign(void) const
{
    return (_grade_to_sign);
}

int AForm::getGradeRequiredToExecute(void) const
{
    return (_grade_to_exec);
}

void AForm::beSigned(const Bureaucrat &bure)
{
    if (bure.getGrade() > _grade_to_sign)
        throw(GradeTooLowException());
    _is_signed = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    std::string type(_type);
    return (type + "GradeTooHighException");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
}

std::ostream &operator<<(std::ostream &o, AForm &Aform)
{
    o << "[Form inAformation]"
      << "\n";
    o << "Name\t\t: " << Aform.getName() << "\n";
    o << "Signed\t\t: " << Aform.getIsSigned() << "\n";
    o << "Required grade\t: " << Aform.getGradeRequiredToSign() << " (to sign)"
      << ", " << Aform.getGradeRequiredToExecute() << " (to execute)"
      << "\n";
    return (o);
}
