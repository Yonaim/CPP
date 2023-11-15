#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int find)
{
	typename T::iterator it = container.begin();
	for (; it != container.end(); it++)
	{
		if (*it == find)
			return (it);
	}
	throw (std::runtime_error("The value to be found is not present in this container."));
}

#endif
