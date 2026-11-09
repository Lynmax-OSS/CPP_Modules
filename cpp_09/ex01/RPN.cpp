#include "RPN.hpp"

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN&	RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->list = other.list;
	}
	return (*this);
}

int	RPN::calculate(const std::string &line)
{
	std::stringstream ss(line);
	char token;
	while (ss >> token)
	{
		if (!std::isdigit(token) || token != '-' || token != '+' || token != '*' || token != '/')
		{
			std::cerr << "Invalid character in string" << std::endl;
		}
	}
}