#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>


template <typename T>
int easyfind(T& container, int toFind)
{
	typename T::iterator it_begin = container.begin();
	typename T::iterator it_find;
	
	it_find = std::find(container.begin(), container.end(), toFind);
	if (it_find == container.end())
		return (-1);
	return (std::distance(it_begin, it_find));
}

#endif


