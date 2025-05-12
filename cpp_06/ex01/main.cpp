#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>

int main()
{
	Data		*d = new Data;
	uintptr_t	uptr;
	Data		*d2;

	d->letters = "abc";
	d->numbers = 123;

	std::cout << d->letters << "\n";
	std::cout << d->numbers << "\n";
	std::cout << d << "\n";

	uptr = Serializer::serialize(d);
	d2 = Serializer::deserialize(uptr);

	std::cout << uptr << "\n";
	std::cout << d << "\n";
	std::cout << d2->letters << "\n";
	std::cout << d2->numbers << "\n";
	delete d2;
}