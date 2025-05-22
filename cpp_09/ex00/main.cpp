#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cerr << "wrong number of arguments\n", 1);
	BitcoinExchange bte;
	std::ifstream input(argv[1]);

	if (!input.is_open())
	{
		std::cerr << "failed to open file" << std::endl;
		return 1;
	}
	std::string line;
	std::getline(input, line);
	if (line != "date | value")
	{
		std::cerr << line << std::endl;
		std::cerr << " invalid input file" << std::endl;
		return 1;
	}
	while (std::getline(input, line))
	{
		bte.display_exchange_rate(line);
	}
	return (0);
}
