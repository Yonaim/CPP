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
	
	template <typename T>
	void addRange(T first, T last) // add [first, last) to _integers
	{
		// 정석은 typename T::iterator를 이용하는 것이지만
		// std::begin, end도 지원하기 위해 다른 형식으로 작성
		while (first != last)
		{
			addNumber(*first);
			first++;
		}
	}
	
	size_t shortestSpan(void) const; // 인접한 수들끼리의 차를 차례대로 계산해보고 가장 작은 값 
	size_t longestSpan(void) const; // 가장 큰 수와 작은 수의 차를 구하고 절댓값
	void showStoredIntegers(void) const;
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
