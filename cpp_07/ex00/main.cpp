#include "whatever.hpp"
#include "iostream"

int main( void ) {
	std::cout << "\nSimple type" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "a and b SWAPED!" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	std::cout << "Complex type" << std::endl;
	std::string c = "chaine2";
	std::string d = "chaine1";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "c and d SWAPED!" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

return 0;
}