#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP
#include <exception>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>

class BitcoinExchange
{
private:
	std::list<std::string> _data;
	double _inputNum;
	bool badInput(std::string line) const;
	bool syntax_check(std::string line);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange& other);
	~BitcoinExchange();
	void display_exchange_rate(std::string line);
};

#endif