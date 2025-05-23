#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n== 1,000 elements ==" << std::endl;
	srand(time(0));
	std::vector<int> newvec;
	for (int i = 0; i < 1000; ++i)
	{
		newvec.push_back(rand());
	}
	Span nsp = Span(1000);
	nsp.addNumber(newvec.begin(), newvec.end());
	std::cout << "shortestspan: " << nsp.shortestSpan() << std::endl;
	std::cout << "longestspan: " << nsp.longestSpan() << std::endl;

	std::cout << "\n== 1,000,000 elements ==" << std::endl;
	std::vector<int> newervec;
	for (int i = 0; i < 1000000; ++i)
	{
		newervec.push_back(rand());
	}
	Span nnsp = Span(1000000);
	nnsp.addNumber(newervec.begin(), newervec.end());
	std::cout << "shortestspan: " << nnsp.shortestSpan() << std::endl;
	std::cout << "longestspan: " << nnsp.longestSpan() << std::endl;
	return 0;
}