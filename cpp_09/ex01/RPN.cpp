#include <stack>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <exception>
#define SIGN 0
#define NUM 1

void pushPop(std::stack<int>& toEmpty, std::stack<int>& toFill)
{
	while (toEmpty.size() > 0)
	{
		toFill.push(toEmpty.top());
		toEmpty.pop();
	}
}

std::stack<int>	setup_rpn(char *argv[])
{
	std::stack<int> deq;
	std::string str = argv[1];
	for (unsigned long i = 0; i < str.length() ; i += 2)
	{
		if ((str[i] == ' ' || str[i] == '\0') || (str[i + 1] != '\0' && str[i + 1] != ' '))
		{
			std::cerr << "invalid input" << std::endl;
			throw std::exception();
		}
		else if (std::isdigit(str[i]) != 0)
		{
			deq.push(NUM);
			deq.push(str[i] - '0');
		}
		else if (std::strchr("+*/-", str[i]))
		{
			deq.push(SIGN);
			deq.push(str[i]);
		}
		else
		{
			std::cerr << "token not allowed" << std::endl;
			throw std::exception();
		}
	}
	std::stack<int> sta;
	pushPop(deq, sta);
	return (sta);
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
	std::stack<int> deq = setup_rpn(argv);
	std::stack<int> store;
	while (deq.size() > 4)
	{
		int num1;
		int num2;
		int sign;
		if (deq.top() != NUM)
		{
			std::cerr << "wrong amount of numbers and signs" << std::endl;
			throw std::exception();
		}
		store.push(deq.top());
		deq.pop();
		store.push(deq.top());
		deq.pop();
		if (deq.top() != NUM)
		{
			std::cerr << "wrong amount of numbers and signs" << std::endl;
			throw std::exception();
		}
		store.push(deq.top());
		deq.pop();
		store.push(deq.top());
		deq.pop();
		while (deq.size() != 0 && deq.top() != SIGN)
		{
			store.push(deq.top());
			deq.pop();
		}
		if (deq.size() == 0) 
		{
			std::cerr << "wrong amount of numbers and signs" << std::endl;
			throw std::exception();
		}
		deq.pop();
		sign = deq.top();
		deq.pop();
		num2 = store.top();
		store.pop();
		store.pop();
		num1 = store.top();
		store.pop();
		int	rez = do_thing(num1, num2, sign);
		store.push(rez);
		pushPop(store, deq);
	}
	if (deq.size() >= 4)
	{
		std::cerr << "wrong amount of numbers and signs" << std::endl;
		throw std::exception();
	}
	return (deq.pop(), deq.top());
}
