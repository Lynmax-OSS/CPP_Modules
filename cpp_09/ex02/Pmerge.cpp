#include "Pmerge.hpp"

Pmerge::Pmerge()
{}

Pmerge::Pmerge(const Pmerge &other)
{
	*this = other;
}

Pmerge&	Pmerge::operator=(const Pmerge &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return (*this);
}

Pmerge::~Pmerge()
{}

int	Pmerge::parseArgs(std::stringstream &ss)
{
	int n;
	while (ss >> n)
	{
		if (n < 0)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		vec.push_back(n);
		deq.push_back(n);
	}
	std::cout << "Before: ";
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	return (0);
}

void	pairAndRecurse(const std::vector<int> &vec, int depth = 0)
{
	
}

int	Pmerge::mergeInsertionVec()
{
	
}