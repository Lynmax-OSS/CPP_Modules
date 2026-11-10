#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Argument not in proper format" << std::endl;
		return (1);
	}
	RPN rpn;
	std::cout << rpn.calculate(av[1]) << std::endl;
	
	return (0);
}