#pragma once
#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>

class RPN
{
	private:
		std::stack<std::deque<int>> list;
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();
		int calculate(const std::string &line);
};

#endif