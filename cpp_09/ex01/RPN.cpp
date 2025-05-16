#include <deque>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <exception>
#define SIGN 0
#define NUM 1


std::deque<int>	setup_rpn(char *argv[])
{
	std::deque<int> deq;
	std::string str = argv[1];
	for (size_t i = 0; i < str.length() ; i += 2)
	{
		if (str[i + 1] != '\0' && str[i + 1] != ' ')
		{
			std::cerr << "invalid input" << std::endl;
			throw std::exception();
		}
		if (std::isdigit(str[i]) == true)
		{
			deq.push_back(NUM);
			deq.push_back(str[i] - '0');
		}
		else if (std::strchr("+*/-", str[i]))
		{
			deq.push_back(SIGN);
			deq.push_back(str[i]);
		}
		else
		{
			std::cerr << "token not allowed" << std::endl;
			throw std::exception();
		}
	}
	return (deq);
}

int	do_thing(int a, int b, int c)
{
	if (c == '*')
		return (a * b);
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '/')
	{
		if (b == 0)
		{
			std::cerr << "dividing by 0" << std::endl;
			throw std::exception();
		}
		return (a / b);
	}
	return (0);
}

// void print_deq(std::deque<int> deq)
// {
// 	for (size_t i = 0; i < deq.size() - 1; i++)
// 	{
// 		std::cout << "[thing: " << deq[i];
// 		i++;
// 		std::cout << " thing2: " << deq[i] << "]";
// 	}
// 	std::cout << "\n" << std::endl;
// }

int	rpn(char *argv[])
{
	std::deque<int> deq = setup_rpn(argv);
	while (deq.size() > 4)
	{
		std::deque<int>::iterator it = deq.begin();	
		if (*it != NUM || *(it + 2) != NUM)
		{
			std::cerr << "wrong amount of numbers and signs" << std::endl;
			throw std::exception();
		}
		while ((it + 4) != deq.end() && *(it + 4) != SIGN)
			it += 2;
		if ((it + 4) == deq.end()) 
		{
			std::cerr << "wrong amount of numbers and signs" << std::endl;
			throw std::exception();
		}
		int	rez = do_thing(*(it + 1), *(it + 3), *(it + 5));
	
		it = deq.erase(it + 2, it + 6);
		it -= 2;
		*(it + 1) = rez;
	}
	if (deq.size() >= 4)
	{
		std::cerr << "wrong amount of numbers and signs" << std::endl;
		throw std::exception();
	}
	return (deq[1]);
}
