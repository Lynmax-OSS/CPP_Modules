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

static size_t	jacobstahl(size_t k)
{
	size_t	a = 0;
	size_t	b = 1;
	for (size_t i = 0; i < k; i++)
	{
		size_t t = b + 2 * a;
		a = b;
		b = t;
	}
	return (a);
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
		n = std::atol(str.c_str());
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
	mergeInsertionVec(ids, vals);
}

void	Pmerge::mergeInsertionVec(std::vector<int> &ids, const std::vector<int> &vec)
{
	size_t n = ids.size();
	if (n < 2)
		return;
	bool	odd = (n % 2 != 0);
	int straggler = odd ? ids[n - 1] : -1;
	std::vector<int> larger;
	std::vector<int> partner(vec.size());
	for (size_t i = 0; i + 1 < n ; i+= 2)
	{
		int a = ids[i];
		int b = ids[i + 1];
		if (vec[a] < vec[b])
			std::swap(a, b);
		larger.push_back(a);
		partner[a] = b;
	}
	mergeInsertionVec(larger, vec);
	size_t m = larger.size();
	std::vector<int> main;
	main.push_back(partner[larger[0]]);
	for (size_t i = 0; i < m; i++)
		main.push_back(larger[i]);
	size_t	pendCount = m + (odd ? 1 : 0);
	ByValue<std::vector<int>> cmp(vec);

	size_t	inserted = 0;
	size_t	prevJ = 1;
	for (size_t k = 3; prevJ < pendCount; ++k)
	{
		size_t curJ = ;
	}
	
}