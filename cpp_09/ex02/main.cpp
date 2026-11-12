#include "Pmerge.hpp"

int main(int ac, char **av)
{
	Pmerge FJ;
	if (ac < 2)
		return (1);
	std::stringstream iss;

	for (size_t i = 1; i < ac ; i++)
		iss << av[i] << " ";
	if (!FJ.parseArgs(iss))
		return (1);
	FJ.mergeInsertionVec();
	return (0);
}
