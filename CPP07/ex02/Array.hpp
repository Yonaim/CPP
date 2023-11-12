#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>
#include <exception>
#include <cstring>
#include <iostream>

template<typename T>
class Array
{
private:
	size_t _size;
	T *_elems;

public:
	class outOfRange : public std::exception
	{
		const char *what(void) const throw()
		{
			return ("out of range");
		}
	};

	Array() : _size(0), _elems(NULL)
	{
		std::cout << "default" << std::endl;
		
	}

	Array(unsigned int n) : _size(n), _elems(NULL)
	{
		_elems = new T[_size];
		std::memset(_elems, 0, sizeof(T) * _size);
	}

	// deep copy
	Array(Array &orig)
	{
		if (_size)
			delete[] _elems;
		_size = orig._size;
		_elems = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_elems[i] = orig._elems[i];
	}

	Array &operator=(Array &orig)
	{
		if (this == &orig)
			return (*this);
		if (_size)
			delete[] _elems;
		_size = orig._size;
		_elems = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_elems[i] = orig._elems[i];
		return (*this);
	}

	~Array()
	{
		if (_size)
			delete[] _elems;
	}

	size_t size() const
	{
		return (_size);
	}

	T &operator[](size_t idx)
	{
		if (idx < 0 || idx >= _size)
			throw (outOfRange());
		return (_elems[idx]);
	}

	const T &operator[](size_t idx) const
	{
		if (idx < 0 || idx >= _size)
			throw (outOfRange());
		return (_elems[idx]);
	}

};

#endif
