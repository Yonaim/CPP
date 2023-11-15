#include "Span.hpp"
#include <iostream>

Span::Span()
{}

Span::Span(unsigned int N) : _capacity(N), _size(0)
{
	_integers.resize(_capacity);
} 

Span::Span(Span &orig) : _integers(orig._integers), _capacity(orig._capacity), _size(0)
{
}

Span &Span::operator=(Span &orig)
{
	_integers = orig._integers;
	_capacity = orig._capacity;
	_size = orig._size;
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_size >= _capacity)
		throw(AlreadyFullException());
	_integers[_size] = n;
	_size++;
}

// 정렬 후 인접한 수들끼리의 차를 차례대로 계산해보고 가장 작은 값 
int Span::shortestSpan(void)
{
	if (_size < 2)
		throw(ThereIsNoSpanException());

	std::vector<int> sorted = _integers;
	std::sort(sorted.begin(), sorted.begin() + _size);
	// std::cout << "\n--------------\n";
	// for (std::vector<int>::const_iterator it = _integers.begin(); it < _integers.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n--------------\n";

	// for (std::vector<int>::const_iterator it = sorted.begin(); it < sorted.begin() + _size; it++)
	// 	std::cout << *it << " ";
	// std::cout << "\n";

	int shortest = INT_MAX;
	for (std::vector<int>::const_iterator it = sorted.begin(); it < sorted.begin() + (_size - 1); it++)
	{
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}

// 가장 큰 수와 작은 수의 차를 구함
int Span::longestSpan(void)
{
	if (_size < 2)
		throw(ThereIsNoSpanException());
	
	std::vector<int>::const_iterator max_it = std::max_element(_integers.begin(), _integers.end()); 
	std::vector<int>::const_iterator min_it = std::min_element(_integers.begin(), _integers.end()); 
	return (*max_it - *min_it);
}

const char *Span::AlreadyFullException::what(void) const throw()
{
	return ("This Span is Already Full");
}

const char *Span::ThereIsNoSpanException::what(void) const throw()
{
	return ("There's no span exist in this Span");
}
