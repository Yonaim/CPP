#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _target("default"), _is_signed(false), _grade_to_sign(100), _grade_to_exec(100)
{
}

AForm::AForm(const std::string &target, int grade_to_sign, int grade_to_exec)
    : _target(target), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
}

AForm::AForm(const AForm &orig)
    : _target(orig.getTarget()), _is_signed(orig.getIsSigned()), _grade_to_sign(orig.getGradeRequiredToSign()),
      _grade_to_exec(orig.getGradeRequiredToExecute())
{
}

AForm &AForm::operator=(const AForm &orig)
{
    if (this != &orig)
    {
        *(const_cast<std::string *>(&_target)) = orig.getTarget();
        _is_signed = orig.getIsSigned();
        *(const_cast<int *>(&_grade_to_sign)) = orig.getGradeRequiredToSign();
        *(const_cast<int *>(&_grade_to_exec)) = orig.getGradeRequiredToExecute();
    }
    return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getTarget(void) const
{
    return (_target);
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

void AForm::setType(const std::string &type)
{
    _type = type;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low");
}

const char *AForm::UnsignedException::what(void) const throw()
{
    return ("Unsigned Form");
}

void AForm::checkExecutable(const Bureaucrat &bure) const
{
    if (_is_signed == false)
        throw (AForm::UnsignedException());
    if (bure.getGrade() > _grade_to_exec)
        throw (AForm::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &o, AForm &Aform)
{
    o << "[Form inAformation]"
      << "\n";
    o << "Name\t\t: " << Aform.getTarget() << "\n";
    o << "Signed\t\t: " << Aform.getIsSigned() << "\n";
    o << "Required grade\t: " << Aform.getGradeRequiredToSign() << " (to sign)"
      << ", " << Aform.getGradeRequiredToExecute() << " (to execute)"
      << "\n";
    return (o);
}
