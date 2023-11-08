#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _target("default"), _is_signed(false), _grade_to_sign(100), _grade_to_exec(100)
{
}

Form::Form(const std::string &target, int grade_to_sign, int grade_to_exec)
    : _target(target), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
}

Form::Form(const Form &orig)
    : _target(orig.getTarget()), _is_signed(orig.getIsSigned()), _grade_to_sign(orig.getGradeRequiredToSign()),
      _grade_to_exec(orig.getGradeRequiredToExecute())
{
}

Form &Form::operator=(const Form &orig)
{
    if (this != &orig)
    {
        // 상수성을 제거하기 위해 const_cast 사용
        // (const_cast는 포인터와 레퍼런스에만 사용 가능)
        *(const_cast<std::string *>(&_target)) = orig.getTarget();
        _is_signed = orig.getIsSigned();
        *(const_cast<int *>(&_grade_to_sign)) = orig.getGradeRequiredToSign();
        *(const_cast<int *>(&_grade_to_exec)) = orig.getGradeRequiredToExecute();
    }
    return (*this);
}

Form::~Form()
{
}

std::string Form::getTarget(void) const
{
    return (_target);
}

bool Form::getIsSigned(void) const
{
    return (_is_signed);
}

int Form::getGradeRequiredToSign(void) const
{
    return (_grade_to_sign);
}

int Form::getGradeRequiredToExecute(void) const
{
    return (_grade_to_exec);
}

void Form::beSigned(const Bureaucrat &bure)
{
    if (bure.getGrade() > _grade_to_sign)
        throw(GradeTooLowException());
    _is_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &o, Form &form)
{
    o << "[Form information]"
      << "\n";
    o << "Name\t\t: " << form.getTarget() << "\n";
    o << "Signed\t\t: " << form.getIsSigned() << "\n";
    o << "Required grade\t: " << form.getGradeRequiredToSign() << " (to sign)"
      << ", " << form.getGradeRequiredToExecute() << " (to execute)"
      << "\n";
    return (o);
}
