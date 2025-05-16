#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP
#include <exception>
#include <queue>
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
private:
	std::queue<std::tuple<std::string, double>> _data;
	std::queue<std::tuple<std::string, double>> _input;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange(std::string data, std::string input);
	std::queue<std::tuple<std::string, double>>& getData();
	std::queue<std::tuple<std::string, double>>& getInput();
};

#endif