#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void)
{
	std::srand(std::time(0));
	Base *b;

	int which_base = rand() % 3;
	switch (which_base)
	{
		case 0:
			b = new A;
			break ;
		case 1:
			b = new B;
			break ;
		case 2:
			b = new C;
			break ;
	}
	return b;
}

void identify(Base* p)
{
	std::cout << "Pointer type check: ";
	std::cout << "type is: ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
	std::cout << "\n";

}

void identify(Base& p)
{
	std::cout << "Reference type check: ";
	std::cout << "type is: ";
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
	}
	catch(const std::exception& e){}
		try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B\n";
	}
	catch(const std::exception& e){}
		try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C\n";
	}
	catch(const std::exception& e){}
}

int main()
{
	Base *base = generate();
	
	identify(base);
	identify(*base);
	delete base;
}