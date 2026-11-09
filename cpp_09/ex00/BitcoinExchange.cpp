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

bool	checkLeapYear(const int &year)
{
	if ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
		return (true);
	else
		return (false);
}

static bool	validDate(const std::string &date)
{
	if (date.size() != 10)
		return (false);
	else if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		else if (!std::isdigit(date[i]))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2000)
		return (false);
	else if (month < 1 || month > 12)
		return (false);
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (checkLeapYear(year))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

static int	validValue(const std::string &value, double & nValue)
{
	std::istringstream ss(value);
	char	extra = 0;
	ss >> nValue;
	ss >> extra;
	if (!nValue || extra)
		return (1);
	if (nValue < 1)
		return (2);
	else if (nValue > 1000)
		return (3);
	return (0);

}

bool	BitcoinExchange::findRecords(const std::string &dateStr, double &rate) const
{
	std::map< std::string, double>::const_iterator it = ratesDb.lower_bound(dateStr);

		if (it->first == dateStr && it != ratesDb.end())
		{
			rate = it->second;
			return (true);
		}
		if (it == ratesDb.begin())
			return (false);
		--it;
		rate = it->second;
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
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input =>" << line << std::endl;
			continue; 
		}
		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 3, line.size());
		double	value;
		double	rate;
		if (!validDate(date))
			std::cerr << "Error: bad input =>" << line << std::endl;
		else
		{
			int status = validValue(valueStr, value); 
			if (status == 1)
				std::cerr << "Error: bad input =>" << line << std::endl;
			else if (status == 2)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (status == 3)
				std::cerr << "Error: too large a number." << std::endl;
			else if (!findRecords(date, rate))
				std::cerr << "Input is older than data records" << std::endl;
			else
				std::cout << date << "=>" << valueStr << "=" << value * rate << std::endl;
		}
	}
	return (true);
}
