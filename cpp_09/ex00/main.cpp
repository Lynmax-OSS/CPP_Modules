#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	try
	{
		BitcoinExchange	btc;
		if (!btc.loadDatabase("data.csv"))
			throw (std::runtime_error("Failed to load database"));
		if (!btc.parseInput(av[1]))
			throw (std::runtime_error("Input file cannot be opened"));
	}
	catch(const std::exception& e)
	{}
}
