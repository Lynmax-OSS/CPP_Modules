#pragma once
#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
	private:
		std::stack<int> list;
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();
		int calculate(const std::string &line);
		bool	parseInput(const std::string &line);
};

#endif