#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <list>

struct Pair
{
	int num;
	bool is_larger;
	bool is_leftover = 0;
	int paired_with;
};

#endif
