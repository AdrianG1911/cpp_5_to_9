#include <vector>
#include <iostream>

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

void recMI(std::vector<std::vector<int>> &vec)
{
	std::vector<int> leftover;

	if (vec.back()[0] == -1)
	{
		leftover = vec.back();
		vec.pop_back();
	}
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i][0] < vec[i][1])
			std::swap(vec[i][0], vec[i][1]);
	}
}

std::vector<int> merginsertion(std::vector<int> v)
{
	int pairs = v.size() / 2;
	std::vector<std::vector<int>> vec(pairs + (v.size() % 2));
	for (int i = 0; i < pairs; i++)
	{
		vec[i][0] = v[(i * 2)];
		vec[i][1] = v[(i * 2) + 1];
	}
	if ((pairs * 2) < v.size())
	{
		vec[pairs][0] = -1;
		vec[pairs][1] = v[v.size() - 1];
	}
	recMI()
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
	(void)argc;
	std::vector<int> v = gFJS(std::stoi(argv[1]));
	putvect(v);
}

