#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <exception>
# include <sstream>

class	BitcoinExchange
{
	private:
		std::map<std::string, double> ratesDb;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		bool	loadDatabase(const std::string &Filepath);
		bool	parseInput(const std::string &FilePath) const;
		bool	findRecords(const std::string &dateStr, double &value) const;
};

bool	validValue(const std::string &value, double & nValue);
#endif