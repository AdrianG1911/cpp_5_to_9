#include <vector>
#include <map>
#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>

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
	while (*(v.end() - 1) < n)
	{
		v.push_back(gJN(i));
		i++;
	}
	return (v);
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

std::vector<int> merginsertion(std::vector<int> v)
{
	if (v.size() == 0 || v.size() == 1)
		return (v);
	int leftover = -1;
	int pairs = v.size() / 2;
	std::map<int, std::vector<int>> wmap;
	std::vector<int> winners;
	for (int i = 0; i < pairs; i++)
	{
		if (v[i * 2] < v[(i * 2) + 1])
			std::swap(v[i * 2], v[(i * 2) + 1]);
		winners.push_back(v[(i * 2)]);
		wmap[v[(i * 2)]].push_back(v[(i * 2) + 1]);
	}
	if (v.size() > (pairs * 2))
		leftover = v.back();
	winners = merginsertion(winners);
	std::vector<int> gfjs = gFJS(pairs); //geting the ford johnson sequence
	std::vector<int> sorted = winners; //copying winners so it does not get changed
	int offset = 0; //after each insertion the offset is incremented just in case.
	for (int i = 0; i < gfjs.size(); i++)
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


std::vector<int> merginsertion_find(std::vector<int> v)
{
	if (v.size() == 0 || v.size() == 1)
		return (v);
	int leftover = -1;
	int pairs = v.size() / 2;
	std::map<int, std::vector<int>> wmap;
	std::vector<int> winners;
	for (int i = 0; i < pairs; i++)
	{
		if (v[i * 2] < v[(i * 2) + 1])
			std::swap(v[i * 2], v[(i * 2) + 1]);
		winners.push_back(v[(i * 2)]);
		wmap[v[(i * 2)]].push_back(v[(i * 2) + 1]);
	}
	if (v.size() > (pairs * 2))
		leftover = v.back();
	winners = merginsertion(winners);
	std::vector<int> gfjs = gFJS(pairs); //geting the ford johnson sequence
	std::vector<int> sorted = winners; //copying winners so it does not get changed
	for (int i = 0; i < gfjs.size(); i++)
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

void putvect(std::vector<int> vec)
{
	int len = vec.size();
	std::cout << "[";
	for (int i = 0; i < len; i++)
	{
		std::cout << " " << vec[i];
	}
	std::cout << " ]\n";
}

int main(int argc, char *argv[])
{
	std::vector<int> v;
	for (int i = 1; i < argc; i++)
		v.push_back(std::stoi(argv[i]));
	std::vector<int> v2 = v;

	clock_t starta = clock();
	v2 = merginsertion(v2);
	clock_t enda = clock();
	std::cout << "find method: " << double(enda - starta) << std::endl;
	//putvect(v);

	clock_t start = clock();
	v = merginsertion(v);
	clock_t end = clock();
	std::cout << "no find method: " << double(end - start) << std::endl;
}

