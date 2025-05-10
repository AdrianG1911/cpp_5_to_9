#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	std::string str = "naninf";
	char c = static_cast<char>(80.2);
	int i = std::atoi(str.c_str());
	float f = std::atof(str.c_str());
	double d = std::atof(str.c_str());
	
	c = c + f;
	std::cout << c << "\n";
	std::cout << i << "\n";
	std::cout << f << "\n";
	std::cout << d << "\n";
	isprint()
}