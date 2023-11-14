#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int find)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), find);
	if (it == container.end())
		throw (std::runtime_error("Not found"));
	return (it);
}

#endif
