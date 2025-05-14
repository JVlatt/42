#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>

class PmergeMe
{
	public:
	static int nbr_of_comps;
};

template <typename T> bool _comp(T lv, T rv) {
	PmergeMe::nbr_of_comps++;
	return (*lv < *rv);
};

#endif
