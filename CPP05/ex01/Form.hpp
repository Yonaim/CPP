#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool			_is_signed = false;
	const int		_grade_to_sign;
	const int		_grade_to_exec;

public:
	Form();
	Form(const std::string &name, int grade_to_sign, int grade_to_exec);
	Form(const Form &orig);
	Form& operator=(const Form &orig);
	~Form();

	std::string getName(void) const;
	bool		getIsSigned(void) const;
	int			getGradeRequiredToSign(void) const;
	int			getGradeRequiredToExecute(void) const;
	void		beSigned(const Bureaucrat &bure);

	class GradeTooHighException : public std::exception
	{
		const char*	what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char*	what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form &form)
{
	o << "[Form information]" << "\n";
	o << "Name: " << form.getName() << "\n";
	o << "Signed: " << form.getIsSigned() << "\n";
	o << "Required grade: " << "\n" \
			<< form.getGradeRequiredToSign() << " (to sign)" << "\n" \
			<< form.getGradeRequiredToExecute() << " (to execute)" << "\n";
	return (o);
}

#endif
