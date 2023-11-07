#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _is_signed(false), _grade_to_sign(100), _grade_to_exec(100)
{
}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_exec)
    : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
}

Form::Form(const Form &orig)
    : _name(orig.getName()), _is_signed(orig.getIsSigned()), _grade_to_sign(orig.getGradeRequiredToSign()),
      _grade_to_exec(orig.getGradeRequiredToExecute())
{
}

Form &Form::operator=(const Form &orig)
{
    if (this != &orig)
    {
        // 상수성을 제거하기 위해 const_cast 사용
        // (const_cast는 포인터와 레퍼런스에만 사용 가능)
        *(const_cast<std::string *>(&_name)) = orig.getName();
        _is_signed = orig.getIsSigned();
        *(const_cast<int *>(&_grade_to_sign)) = orig.getGradeRequiredToSign();
        *(const_cast<int *>(&_grade_to_exec)) = orig.getGradeRequiredToExecute();
    }
    return (*this);
}

Form::~Form()
{
}

std::string Form::getName(void) const
{
    return (_name);
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
    o << "Name\t\t: " << form.getName() << "\n";
    o << "Signed\t\t: " << form.getIsSigned() << "\n";
    o << "Required grade\t: " << form.getGradeRequiredToSign() << " (to sign)"
      << ", " << form.getGradeRequiredToExecute() << " (to execute)"
      << "\n";
    return (o);
}
