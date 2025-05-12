#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();                            // Default constructor
    Serializer(const Serializer& other);  // Copy constructor
    Serializer& operator=(const Serializer& other); // Copy assignment
    ~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif