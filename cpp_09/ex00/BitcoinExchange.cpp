#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->ratesDb = other.ratesDb;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

bool	BitcoinExchange::loadDatabase(const std::string &Filepath)
{
	std::ifstream file(Filepath.c_str());
	std::string	line;

	if (!file.is_open())
		return (false);
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	pos = line.find(",");
		if (pos == std::string::npos)
			continue;
		const char * start = line.c_str() + pos + 1;
		char *end;
		double	rate = std::strtod(start, &end);
		if (end == start || *end != '\0')
			continue;
		ratesDb.insert(std::make_pair(line.substr(0, pos), rate));
	}
	file.close();
	return (true);
}

bool	BitcoinExchange::parseInput(const std::string &Filepath) const
{
	std::ifstream file(Filepath.c_str());
	std::string line;

	if (!file.is_open())
		return (false);
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	pos = line.find(" | ");
		if (pos == std::string::npos);
			continue;
		
	}
}
