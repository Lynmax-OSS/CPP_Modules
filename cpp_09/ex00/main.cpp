#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	try
	{
		BitcoinExchange	btc;
		if (!btc.loadDatabase("data.csv"))
			return (std::cerr << "failed to load database." << std::endl, 1);
	}
	catch(const std::exception& e)
	{
	}
	
}
