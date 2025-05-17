#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() : _inputNum(0)
{
	std::ifstream dataIn("data.csv");

	if (!dataIn.is_open())
	{
		std::cerr << "failed to open file" << std::endl;
		std::exit(1);
	}
	std::string line;
	std::getline(dataIn, line);
	while (std::getline(dataIn, line))
	{
		_data.push_back(line);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
 : _data(other._data), _inputNum(other._inputNum)
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	_data = other._data;
	_inputNum = other._inputNum;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool safe_stof(const std::string& str, double& result) {
    std::stringstream ss(str);
    ss >> result;

    if (ss.fail() || !ss.eof())
        return false;

    return true;
}


bool BitcoinExchange::badInput(std::string line) const
{
	std::cerr << "Error: bad input => " << line << std::endl;
	return false;
}

bool BitcoinExchange::syntax_check(std::string line)
{
	if (line.length() < 14)
		return (badInput(line));
	int i = -1;
	while (++i < 4)
	{
		if (isdigit(line[i]) == false)
			return  badInput(line);
	}
	if (line[i] != '-')
		return badInput(line);
	while (++i < 7)
	{
		if (isdigit(line[i] == false))
			return badInput(line);
	}
	if (line[i] != '-')
		return badInput(line);
	while (++i < 10)
	{
		if (isdigit(line[i] == false))
			return badInput(line);
	}
	if (line.substr(i, 3) != " | ")
		return badInput(line);
	i += 3;
	double num = 0;
	if (safe_stof(line.substr(i), num) == false)
		return badInput(line);
	if (num <= 0)
		return (std::cerr << "Error: not a positive number.\n", false);
	if (num >= 1000)
		return (std::cerr << "Error: too large a number.\n", false);
	_inputNum = num;
	return (true);
}

void BitcoinExchange::display_exchange_rate(std::string line)
{
	if (syntax_check(line) == false)
		return ;
	std::string left = line.substr(0, 10);
	std::list<std::string>::iterator it = _data.begin();
	while (it != _data.end() && (*it).substr(0, 10) <= left)
		it++;
	if (it != _data.begin())
		it--;
	std::cout << (*it).substr(0, 10);
	std::cout << " => " << _inputNum << " = ";
	double mult;
	safe_stof((*it).substr(11), mult);
	std::cout << _inputNum * mult << std::endl;
}
