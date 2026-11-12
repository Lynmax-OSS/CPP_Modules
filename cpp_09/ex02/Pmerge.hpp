#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP
# include <iostream>
# include <sstream>
# include <vector>
# include <deque> 

class Pmerge
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;
	public:
		Pmerge();
		Pmerge(const Pmerge &other);
		Pmerge& operator=(const Pmerge &other);
		~Pmerge();
		int	parseArgs(std::stringstream &ss);
		int	mergeInsertionVec();
};

#endif