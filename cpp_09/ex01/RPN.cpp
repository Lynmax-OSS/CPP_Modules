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
	std::string str;
	int a;
	int b;

	while (ss >> str)
	{
		if (str.size() == 1 && std::isdigit(str.c_str()[0]))
		{
			int tmp = str.c_str()[0] - '0';
			list.push(tmp);
		}
		else if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			if (list.size() != 2)
			{
				std::cerr << "only 2 elements can operate" << std::endl;
				return (1);
			}
			b = list.top();
			list.pop();
			a = list.top();
			list.pop();

			switch (str.c_str()[0])
			{
				case '+':
					list.push(a + b);
					break;
				case '-':
					list.push(a - b);
					break;
				case '*':
					list.push(a * b);
					break;
				case '/':
					if (b == 0)
					{
						std::cerr << "Cannot divide by 0" << std::endl;
						return (0);
					}
					list.push(a / b);
			} 
		}
		else
		{
			std::cerr << "Invalid input in string " << str << std::endl;
			return (-1);
		}
	}
	return (list.top());
}