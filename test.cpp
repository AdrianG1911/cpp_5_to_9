#include <vector>
#include <iostream>

std::vector<int> fj(int n, int push)
{
	std::vector<int> v;
	if (n  == 1)
	{
		return v;
	}
	if (n == 2)
	{
		v.push_back(1 + push);
		return v;
	}
	int k = n / 2;
	std::vector<int> newv = fj(k, push);
	v.insert(v.end(), newv.begin(), newv.end());
	v.push_back(k + push);
	std::vector<int> newerv = fj(n - k - 1, k + 1 + push);
	v.insert(v.end(), newerv.begin(), newerv.end());
	return v;
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

int main()
{
	std::vector<int> s5 = fj(4, 0);
	std::vector<int> s12 = fj(12, 0);

	putvect(s5);;
	putvect(s12);
}