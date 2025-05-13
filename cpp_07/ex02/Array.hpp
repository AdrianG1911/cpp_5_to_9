#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
	T		*arr;
	unsigned int 	_len;
public:
	Array() : arr(NULL), _len(0) {};
	Array(unsigned int _len) : _len(_len)
	{
		arr = new T[_len];
	}
	Array(const Array& other) : _len(other._len)
	{
		arr = new T[_len];
		for (unsigned int i = 0; i < _len; ++i)
			arr[i] = other.arr[i];
	}
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] arr;
			this->_len = other._len;
			arr = new T[_len];
			for (unsigned int i = 0; i < _len; ++i)
				arr[i] = other.arr[i];
		}
		return *this;
	}
	~Array()
	{
		delete[] arr;
	}

	T& operator[](unsigned int index)
	{
		if (index > _len - 1)
			throw std::out_of_range("Error, index out of range");
		return arr[index];
	}

	const T& operator[](unsigned int index) const
	{
		if (index > _len - 1)
			throw std::out_of_range("Error, index out of range");
		return arr[index];
	}
	unsigned int size() const
	{
		return (_len);
	}
};

#endif