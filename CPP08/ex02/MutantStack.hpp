#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
// #include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// stack은 container adaptor로, 내부적으로 다른 컨테이너가 들어있어 container_type(멤버 변수로 타입 저장)의 iterator를 써야함
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// consturctor, desturctor, operator=
	// top, empty, size, push, pop
	// iterator, const_iterator, reverse_iterator, const_reverse_iterator

	MutantStack(void) {}
	MutantStack(MutantStack &orig)
	{
		*this = orig;
	}
	MutantStack &operator=(const MutantStack &orig)
	{
		if (this != &orig)
			this->c = orig->c;
		return (*this);
	}
	~MutantStack(void) {}

	iterator begin(void)
	{
		return (this->c.begin());
	}

	iterator end(void)
	{
		return (this->c.end());
	}

	const_iterator begin(void) const
	{
		// std::cout << "This is const begin: ";
		return (this->c.begin());
	}

	const_iterator end(void) const
	{
		// std::cout << "This is const end: ";
		return (this->c.end());
	}

	reverse_iterator rbegin(void)
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend(void)
	{
		return (this->c.rend());
	}

	const_reverse_iterator rbegin(void) const
	{
		// std::cout << "This is const rbegin: ";
		return (this->c.rbegin());
	}

	const_reverse_iterator rend(void) const
	{
		// std::cout << "This is const rend: ";
		return (this->c.rend());
	}
};

#endif
