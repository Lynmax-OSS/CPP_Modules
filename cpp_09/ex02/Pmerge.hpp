#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <climits>

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
		void	fordJohnsonVector(std::vector<int> &vec);
		int	mergeInsertionVec(const std::vector<int> &vec);
		void	fordJohnsonDeque(std::deque<int> &deq);
		int	mergeInsertionVec(const std::deque<int> &deq);
};

#endif