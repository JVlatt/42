#include <cmath>

#include "PmergeMe.hpp"

int PmergeMe::nbr_of_comps = 0;

long get_jacobsthal(long _n)
{
	return (round((pow(2, _n + 1) + pow(-1, _n)) / 3));
}

std::vector<int> ft_sort_vec(std::vector<int> &_vec)
{
	std::vector<int> _copy(_vec);
	mergeInsterFJ(_copy, 1);
	return (_copy);
}

std::deque<int> ft_sort_deque(std::vector<int> &_vec)
{
	std::deque<int> _deque (_vec.begin(), _vec.end());
	mergeInsterFJ(_deque, 1);
	return (_deque);
}
