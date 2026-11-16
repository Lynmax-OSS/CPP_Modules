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

static bool	isValidNumber(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

int	Pmerge::parseArgs(std::stringstream &ss)
{
	long n;
	std::string str;
	while (ss >> str)
	{
		if (!isValidNumber(str))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		n = std::atoi(str.c_str());
		if (n < 0 || n > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		vec.push_back(n);
		deq.push_back(n);
	}
	if (vec.empty() || deq.empty())
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	return (0);
}

void	Pmerge::fordJohnsonVector(std::vector<int> &vec)
{
	std::vector<int> vals = vec;
	std::vector<int> ids;

	for (size_t i = 0; i < vals.size(); i++)
		ids.push_back(static_cast<int>(i));
	
}

int	Pmerge::mergeInsertionVec(const std::vector<int> &vec)
{

}