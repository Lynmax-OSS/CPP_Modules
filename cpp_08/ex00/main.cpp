#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::srand(time(NULL));

	std::vector<int> vec;
	std::vector<int>::iterator it = vec.begin();

	for (int i = 0; i < 10; i++)
		vec.push_back(rand());
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	if (easyfind(vec, rand()) == 1)
		std::cout << "Found digit" << std::endl;
	else
	{
		std::cout << "Digit not in container" << std::endl;
		return (1);
	}
	return (0);
}
