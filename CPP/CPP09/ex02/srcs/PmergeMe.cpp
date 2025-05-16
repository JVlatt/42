#include <cmath>

#include "PmergeMe.hpp"

int PmergeMe::nbr_of_comps = 0;

long get_jacobsthal(long _n)
{
	return (round((pow(2, _n + 1) + pow(-1, _n)) / 3));
}
