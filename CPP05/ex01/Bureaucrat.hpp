#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	std::string _name;
	int			_grade;
	static const std::string default_name;
	static const int default_grade = 100;

public:
	static const int highest_grade = 1;
	static const int lowest_grade = 150;

	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &orig);
	Bureaucrat& operator=(const Bureaucrat &orig);
	~Bureaucrat();

	std::string getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);

	void		signForm(Form &form) const;

	class GradeTooHighException : public std::exception
	{
		const char*	what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char*	what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	return (o << b.getName() << ", bureaucrat grade" << b.getGrade() << ".");
}

#endif
