#include "PmergeMe.hpp"

void putvect(std::vector<int> vec)
{
	std::cout << "[";
	for (size_t i = 0; i < vec.size() && i < 4; i++)
	{
		std::cout << " " << vec[i];
	}
	if (vec.size() == 5)
		std::cout << " " << vec[4];
	else if (vec.size() > 5)
		std::cout << " " << "...";
	std::cout << " ]\n";
}

void putlist(std::list<int> lis)
{
	std::list<int>::iterator it = lis.begin();
	std::cout << "[";
	for (size_t i = 0; i < lis.size() && i < 4 ; i++)
	{
		std::cout << " " << *it;
		it++;
	}
	if (lis.size() == 5)
		std::cout << " " << *it;
	else if (lis.size() > 5)
		std::cout << " " << "...";
	std::cout << " ]\n";
}

//Individual number jenerator for gJ
int gJN(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (gJN(n - 1) + (2 * gJN(n - 2)));
}

std::vector<int> gJS(int n)
{
	std::vector<int> v;
	v.push_back(gJN(0));
	int i = 1;
	while (v.back() < n)
	{
		v.push_back(gJN(i));
		i++;
	}
	return (v);
}

std::list<int> gJSL(int n)//gJS for lists
{
	std::list<int> l;
	l.push_back(gJN(0));
	int i = 1;
	while (l.back() < n)
	{
		l.push_back(gJN(i));
		i++;
	}
	return l;
}

std::vector<int> gFJS(int n_pairs)
{
	std::vector<int> v;
	std::vector<int> gjs;
	gjs = gJS(n_pairs + 5);
	int last_pair_index = 0;
	size_t gjs_id = 2;
	while (last_pair_index < n_pairs)
	{
		int cur_gjs_val = gjs[gjs_id];
		int chunk_upper_bound = std::min(cur_gjs_val, n_pairs);
		int chunk_lower_bound = last_pair_index + 1;
		if (chunk_upper_bound >= chunk_lower_bound)
		{
			for (int pair_idx_to_insert = chunk_upper_bound; pair_idx_to_insert >= chunk_lower_bound; --pair_idx_to_insert)
				v.push_back(pair_idx_to_insert);
		}
		last_pair_index = chunk_upper_bound;
		gjs_id++;
	}
	return (v);
}


std::list<int> gFJSL(int n_pairs)
{
	std::list<int> l;
	std::list<int> gjs;
	gjs = gJSL(n_pairs + 5);
	int last_pair_index = 0;
	std::list<int>::iterator gjsit = gjs.begin();
	gjsit++;
	gjsit++;
	while (last_pair_index < n_pairs)
	{
		int cur_gjs_val = *gjsit;
		int chunk_upper_bound = std::min(cur_gjs_val, n_pairs);
		int chunk_lower_bound = last_pair_index + 1;
		if (chunk_upper_bound >= chunk_lower_bound)
		{
			for (int pair_idx_to_insert = chunk_upper_bound; pair_idx_to_insert >= chunk_lower_bound; --pair_idx_to_insert)
				l.push_back(pair_idx_to_insert);
		}
		last_pair_index = chunk_upper_bound;
		gjsit++;
	}
	return (l);
}



std::vector<int> merginsertion_nofind(std::vector<int>& v)
{
	if (v.size() == 0 || v.size() == 1)
		return (v);
	int leftover = -1;
	int pairs = v.size() / 2;
	std::map<int, std::vector<int> > wmap;
	std::vector<int> winners;
	for (int i = 0; i < pairs; i++)
	{
		if (v[i * 2] < v[(i * 2) + 1])
			std::swap(v[i * 2], v[(i * 2) + 1]);
		winners.push_back(v[(i * 2)]);
		wmap[v[(i * 2)]].push_back(v[(i * 2) + 1]);
	}
	if (v.size() > (size_t)(pairs * 2))
		leftover = v.back();
	winners = merginsertion_nofind(winners);
	std::vector<int> gfjs = gFJS(pairs); //geting the ford johnson sequence
	std::vector<int> sorted = winners; //copying winners so it does not get changed
	int offset = 0; //after each insertion the offset is incremented just in case.
	for (size_t i = 0; i < gfjs.size(); i++)
	{
		int winner_index = gfjs[i] - 1;
		int winner = winners[winner_index];
		int loser = wmap[winner].back();
		wmap[winner].pop_back();
		std::vector<int>::iterator end = sorted.begin() + winner_index + offset;
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), end, loser);
		sorted.insert(pos, loser);
	}
	if (leftover == -1)
		return sorted;
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), leftover);
	sorted.insert(pos, leftover);
	return sorted;
}

std::vector<int> merginsertionV(std::vector<int>& v)
{
	if (v.size() == 0 || v.size() == 1)
		return (v);
	int leftover = -1;
	int pairs = v.size() / 2;
	std::map<int, std::vector<int> > wmap;
	std::vector<int> winners;
	for (int i = 0; i < pairs; i++)
	{
		if (v[i * 2] < v[(i * 2) + 1])
			std::swap(v[i * 2], v[(i * 2) + 1]);
		winners.push_back(v[(i * 2)]);
		wmap[v[(i * 2)]].push_back(v[(i * 2) + 1]);
	}
	if (v.size() > (size_t)(pairs * 2))
		leftover = v.back();
	winners = merginsertionV(winners);
	std::vector<int> gfjs = gFJS(pairs); //geting the ford johnson sequence
	std::vector<int> sorted = winners; //copying winners so it does not get changed
	for (size_t i = 0; i < gfjs.size(); i++)
	{
		int winner_index = gfjs[i] - 1;
		int winner = winners[winner_index];
		int loser = wmap[winner].back();
		wmap[winner].pop_back();
		std::vector<int>::iterator end = std::find(sorted.begin(), sorted.end(), winner);
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), end, loser);
		sorted.insert(pos, loser);
	}
	if (leftover == -1)
		return sorted;
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), leftover);
	sorted.insert(pos, leftover);
	return sorted;
}

std::list<int> merginsertionL(std::list<int>& l)
{
	if (l.size() == 0 || l.size() == 1)
		return (l);
	int leftover = -1;
	int pairs = l.size() / 2;
	std::map<int, std::list<int> > wmap;
	std::list<int> winners;
	std::list<int>::iterator it1 = l.begin();
	for (int i = 0; i < pairs; i++)
	{
		int num1 = *it1;
		it1++;
		int num2 = *it1;
		if (num1 < num2)
			std::swap(num1, num2);
		winners.push_back(num1);
		wmap[num1].push_back(num2);
		it1++;
	}
	if (l.size() > (size_t)(pairs * 2))
		leftover = l.back();
	winners = merginsertionL(winners);
	std::list<int> gfjs = gFJSL(pairs); //geting the ford johnson sequence
	std::list<int> sorted = winners; //copying winners so it does not get changed
	for (std::list<int>::iterator gfjsit = gfjs.begin(); gfjsit != gfjs.end(); gfjsit++)
	{
		int winner_index = *gfjsit - 1;
		std::list<int>::iterator winit = winners.begin();
		std::advance(winit, winner_index);
		int winner = *winit;
		int loser = wmap[winner].back();
		wmap[winner].pop_back();
		std::list<int>::iterator end = std::find(sorted.begin(), sorted.end(), winner);
		std::list<int>::iterator pos = std::lower_bound(sorted.begin(), end, loser);
		sorted.insert(pos, loser);
	}
	if (leftover == -1)
		return sorted;
	std::list<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), leftover);
	sorted.insert(pos, leftover);
	return sorted;
}