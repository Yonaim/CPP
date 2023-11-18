#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>

template <typename T>
void iter(T *arr, size_t arr_len, void (*f)(T &))
{
	for (size_t i = 0; i < arr_len; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void iter(const T *arr, size_t arr_len, void (*f)(const T &))
{
	for (size_t i = 0; i < arr_len; i++)
	{
		f(arr[i]);
	}
}

#endif
