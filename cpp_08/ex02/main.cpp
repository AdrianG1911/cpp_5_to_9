#include "MutantStack.hpp"
#include <vector>

int main()
{
	std::cout << "==MutantStack results==" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	//same thing but with vector
	std::cout << "== now with vector for comparisson==" << std::endl;

	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << vec[vec.size() - 1] << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);

	vec.push_back(0);
	std::vector<int>::iterator itv = vec.begin();
	std::vector<int>::iterator itve = vec.end();
	++it;
	--it;
	while (itv != itve)
	{
		std::cout << *itv << std::endl;
		++itv;
	}
	std::vector<int> v(vec);

}