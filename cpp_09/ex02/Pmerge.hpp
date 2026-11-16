#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <climits>

template <typename C>
struct ByValue
{
	const C& v;
	ByValue(const C& vals) : v(vals) {}
	bool operator()(int a, int b) const
		{ return v[a] < v[b]; }
};

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
		void	mergeInsertionVec(std::vector<int> &ids, const std::vector<int> &vec);
		void	fordJohnsonDeque(std::deque<int> &deq);
		void	mergeInsertionVec(std::deque<int> &ids, const std::deque<int> &deq);
};

#endif