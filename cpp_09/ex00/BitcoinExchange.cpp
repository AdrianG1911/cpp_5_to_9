#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data(), _input()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
 : _data(other._data), _input(other._input)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	_data = other._data;
	_input = other._input;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string data, std::string input)
{
	std::ifstream dataIn(data);
	std::ifstream inputIn(input);

	if (!dataIn.is_open() || !inputIn.is_open())
	{
		std::cerr << "failed to open files" << std::endl;
		std::exit(1);
	}
	std::string line;
	std::getline(dataIn, line);
	while (std::getline(dataIn, line))
	{
		std::tuple<std::string, double> tup(line.substr(0, 10), std::stof(line.substr(11)));
		_data.push(tup);
	}
}

std::queue<std::tuple<int, float>>& BitcoinExchange::getData()
{
	return _data;
}

std::queue<std::tuple<int, float>> &BitcoinExchange::getInput()
{
	return _input;
}
