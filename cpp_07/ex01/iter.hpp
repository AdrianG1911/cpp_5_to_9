#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <typename array, typename function>
void iter(array *arr, size_t len, function func)
{
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}

#endif