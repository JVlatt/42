#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <iterator>

#include "Colors.hpp"

class PmergeMe
{
	public:
	static int nbr_of_comps;
};


template <typename T>
bool ft_comp(T lv, T rv)
{
	PmergeMe::nbr_of_comps++;
	return (*lv < *rv);
};

template <typename T> T getNextIt(T _it, int _moveCount)
{
	std::advance(_it, _moveCount);
	return (_it);
}

template <typename T> void ft_swap(T _it, int _level)
{
	T start_it = getNextIt(_it, -_level + 1);
	T end_it = getNextIt(start_it, _level);
	int swapcount = 0;

	while (start_it != end_it)
	{
		std::iter_swap(start_it, getNextIt(start_it, _level));
		start_it++;
		swapcount++;
	}
	std::cout << " : " << swapcount << " occured";
}

template <typename T>
void mergeInsterFJ(T &_container, int _level)
{
	typedef typename T::iterator Iter;

	int pair_nb = _container.size() / _level;
	if (pair_nb < 2)
		return ;

	bool isOdd = pair_nb % 2 == 1;

	Iter it_start = _container.begin();
	Iter it_last = getNextIt(_container.begin(), _level * pair_nb);
	Iter it_end = getNextIt(it_last, -(isOdd * _level));
	int jump_size = 2 * _level;

	for (Iter it = it_start; it != it_end; it = getNextIt(it, jump_size))
	{
		Iter pair_one = getNextIt(it, _level - 1);
		Iter pair_two = getNextIt(it, _level * 2 - 1);
		std::cout << "Pair A = " << *pair_one << ", Pair B = " << *pair_two;
		if (ft_comp(pair_two, pair_one))
		{
			ft_swap(pair_one, _level);
		}
		std::cout << std :: endl;
	}
	mergeInsterFJ(_container, _level * 2);
	int rank = 0;
	int color = 1;
	std::cout << "Afer : ";
	for (Iter it = _container.begin(); it != _container.end(); it++)
	{
		std::cout << RESET;
		if (color > 0)
			std::cout << GREEN;
		std::cout << *it << " ";
		if (rank >= 1)
		{
			color *= -1;
			rank = 0;
		}
		else
			rank++;
		std::cout << RESET;
	}
	std::cout << std::endl;
}

#endif
