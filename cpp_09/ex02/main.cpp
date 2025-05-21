#include "PmergeMe.hpp"
#include <sstream>

bool safe_stoi(const std::string& str, int& result) {
    std::stringstream ss(str);
    ss >> result;

    if (ss.fail() || !ss.eof())
        return false;

    return true;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (std::cerr << "Error\n", 1);
	std::vector<int> v;
	std::list<int> l;
	std::list<int> lprep;
	int num_elements;
	for (int i = 1; i < argc; i++)
	{
		int result;
		if (safe_stoi(argv[i], result) == false)
			return (std::cerr << "Error\n", 1);
		if (result < 0)
			return (std::cerr << "Error\n", 1);
		lprep.push_back(result);
		num_elements = i;
	}
	std::cout << "Before: ";
	putlist(lprep);
	//vector
	clock_t start = clock();
	for (int i = 1; i < argc; i++)
	{
		int result;
		safe_stoi(argv[i], result);
		v.push_back(result);
	}
	v = merginsertionV(v);
	clock_t end = clock();
	clock_t clocks_taken = end - start;
	double time_taken_microseconds_v = (double)clocks_taken * (1000000.0 / CLOCKS_PER_SEC);
	//list
	start = clock();
	for (int i = 1; i < argc; i++)
	{
		int result;
		safe_stoi(argv[i], result);
		l.push_back(result);
	}
	l = merginsertionL(l);
	end = clock();
	clocks_taken = end - start;
	double time_taken_microseconds_l = (double)clocks_taken * (1000000.0 / CLOCKS_PER_SEC);
	std::cout << "After:  ";
	putlist(l);
	std::cout << "Time to process a range of " << num_elements << " elements with std::vector : ";
	std::cout << time_taken_microseconds_v << " us" << std::endl;
	std::cout << "Time to process a range of " << num_elements << " elements with std::list : ";
	std::cout << time_taken_microseconds_l << " us" << std::endl;
	return (0);
}