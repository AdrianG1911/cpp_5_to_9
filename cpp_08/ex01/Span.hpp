#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
private:
	unsigned int			_len;
	std::vector<int>		_arr;
public:
	Span();
	Span(unsigned int len);
	Span(const Span& other);
	Span& operator=(const Span&other);
	~Span();
	void addNumber(int num);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class MaxSizeException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif