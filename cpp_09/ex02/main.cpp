#include "Pmerge.hpp"

int main(int ac, char **av)
{
	Pmerge FJ;
	std::stringstream iss;
	if (ac < 2)
		return (1);
	for (int i = 1; i < ac ; i++)
		iss << av[i] << " ";
	if (FJ.parseArgs(iss))
		return (1);
	double startVec = nowUs(); 
	FJ.fordJohnsonVector(FJ.getVector());
	double	elapsedVec = nowUs() - startVec;
	double	startDeq = nowUs();
	FJ.fordJohnsonDeque(FJ.getDeque());
	double	elapsedDeq = nowUs() - startDeq;
	FJ.printContainer(FJ.getVector(), "After: ");
	FJ.printElapsedTime(elapsedVec, elapsedDeq);
	return (0);
}
