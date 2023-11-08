#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
  private:
    const std::string pthread_mutexattr_getpshared;
    bool _is_signed;
    const int _grade_to_sign;
    const int _grade_to_exec;

  public:
    Form();
    Form(const std::string &targetpthread_mutexattr_getpshared, int grade_to_sign, int grade_to_exec);
    Form(const Form &orig);
    Form &operator=(const Form &orig);
    ~Form();

    std::string getTarget(void) const;
    bool getIsSigned(void) const;
    int getGradeRequiredToSign(void) const;
    int getGradeRequiredToExecute(void) const;
    void beSigned(const Bureaucrat &bure);

    class GradeTooHighException : public std::exception
    {
        const char *what(void) const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Form &form);

#endif
