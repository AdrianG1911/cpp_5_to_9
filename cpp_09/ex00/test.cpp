#include <sstream>
#include <string>
#include <iostream>

bool safe_stof(const std::string& str, float& result) {
    std::stringstream ss(str);
    ss >> result;

    // Check if conversion failed or if there are leftover characters
    if (ss.fail() || !ss.eof())
        return false;

    return true;
}

int main ()
{
	// Example usage:
	std::string input = "3.14";
	float value;
	if (safe_stof(input, value)) {
		std::cout << "Parsed: " << value << std::endl;
	} else {
		std::cout << "Invalid number" << std::endl;
	}
}