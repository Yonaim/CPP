#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

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

	class GradeTooHighException : public std::exception
	{
		// std::exception의 what()을 오버라이딩
		const char*	what(void) const throw();
		// 함수 원형의 throw()는 예외(exception)가 발생하지 않음을 의미
		// C++11부터는 noexcept 키워드로 대체
	};

	class GradeTooLowException : public std::exception
	{
		const char*	what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);

#endif
