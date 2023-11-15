#ifndef SPAN_HPP
#define SPAN_HPP

#include <stddef.h>
#include <vector>
#include <exception>

class Span
{
private:
	std::vector<int> _integers;
	size_t _capacity;
	size_t _size;

public:
	Span();
	Span(unsigned int N);
	Span(Span &orig);
	Span &operator=(Span &orig);
	~Span();

	void addNumber(int n);
	int shortestSpan(void); // 인접한 수들끼리의 차를 차례대로 계산해보고 가장 작은 값 
	int longestSpan(void); // 가장 큰 수와 작은 수의 차를 구하고 절댓값

	class AlreadyFullException : public std::exception
	{
		const char *what(void) const throw();
	};

	class ThereIsNoSpanException : public std::exception
	{
		const char *what(void) const throw();
	};
};

#endif
