#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
  private:
    const std::string _name;
    std::string _target;
    bool _is_signed;
    const int _grade_to_sign;
    const int _grade_to_exec;

    void CheckIsValidGrade(int grade) const;

  public:
    AForm();
    AForm(const std::string &target);
    AForm(const std::string &name, int grade_to_sign, int grade_to_exec);
    AForm(const AForm &orig);
    AForm &operator=(const AForm &orig);
    virtual ~AForm();

    std::string getName(void) const;
    std::string getTarget(void) const;
    bool getIsSigned(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;
    void checkExecutable(const Bureaucrat &bure) const;
    void beSigned(const Bureaucrat &bure);
    void setTarget(const std::string &target);

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what(void) const throw();
    };

    class UnsignedException : public std::exception
    {
        const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, AForm &form);

#endif
