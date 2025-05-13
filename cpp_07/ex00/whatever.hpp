#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <ostream>

template <typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T& a, T& b)
{
	if (b <= a)
		return (b);
	return (a);
}

template <typename T>
T max(T& a, T& b)
{
	if (b >= a)
		return (b);
	return (a);
}

// template <typename T>
// std::ostream& operator<<(std::ostream& o, T t)
// {
// 	o << t;
// 	return (o);
// }
#endif