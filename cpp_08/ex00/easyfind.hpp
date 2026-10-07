#pragma once
#include <iostream>
#include <vector>

template <typename T>
int	easyfind(T vec, int n)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (*it == n)
			return (1);
	}
	return (0);
}
