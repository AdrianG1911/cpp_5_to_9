#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <ctime>
#include <algorithm>


std::list<int>		merginsertionL(std::list<int>& l);
std::vector<int>	merginsertionV(std::vector<int>& v);
std::vector<int>	merginsertion_nofind(std::vector<int>& v);
void				putlist(std::list<int> lis);
void				putvect(std::vector<int> vec);
#endif
