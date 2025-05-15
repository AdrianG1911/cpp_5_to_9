#include "Span.hpp"

Span::Span() : _len(0), _arr(0)
{
}

Span::Span(unsigned int len) : _len(len), _arr(0)
{
}

Span::Span(const Span &other) : _len(other._len), _arr(other._arr)
{
}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	_len = other._len;
	_arr = other._arr;
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (_arr.size() == _len)
		throw MaxSizeException();
	_arr.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	if (_arr.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> arrCopy = _arr;
	std::sort(arrCopy.begin(), arrCopy.end());
	unsigned int shortSpan = UINT_MAX;
	for (size_t i = 0; i < arrCopy.size() - 1; ++i)
	{
		long big = std::max(arrCopy[i], arrCopy[i + 1]);
		long small = std::min(arrCopy[i], arrCopy[i + 1]);
		unsigned int check = (unsigned int)(big - small);
		shortSpan = std::min(shortSpan, check);
	}
	return (shortSpan);
}

unsigned int Span::longestSpan() const
{
	if (_arr.size() < 2)
		throw NotEnoughNumbersException();
	long	big = (long)(*std::max_element(_arr.begin(), _arr.end()));
	long	small = (long)(*std::min_element(_arr.begin(), _arr.end()));
	return ((unsigned int)(big - small));
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_arr.size() + std::distance(begin, end) > _len)
		throw MaxSizeException();
	_arr.insert(_arr.end(), begin, end);
}

const char* Span::MaxSizeException::what() const throw()
{
    return "Span has reached its maximum size. Cannot add more numbers.";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers in Span to perform this operation.";
}