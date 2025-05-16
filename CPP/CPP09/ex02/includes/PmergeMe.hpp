#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <iterator>
#include <algorithm>

#include "Colors.hpp"

class PmergeMe
{
	public:
	static int nbr_of_comps;
};

long get_jacobsthal(long _n);

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

	while (start_it != end_it)
	{
		std::iter_swap(start_it, getNextIt(start_it, _level));
		start_it++;
	}
}

template <typename T>
void printArray(T &_container, int _level)
{
	typedef typename T::iterator Iter;

	bool color = true;
	size_t count = 0;
	std::cout << RESET << "Level " << _level << " : ";
	for (Iter it = _container.begin(); it != _container.end(); it++)
	{
		if (color)
		{
			std::cout << GREEN;
		}
		if (_container.size() - count + 1 < static_cast<long unsigned int>(_level * 2) && _container.size() % (_level * 2) != 0)
			std::cout << RED;

		std::cout << *it << " ";
		if (count + 1 > 0 && (count + 1) % (_level * 2) == 0)
		{
			color = !color;
			if (!color)
				std::cout << RESET;
		}
		count++;
	}
	std::cout << std::endl;

}

template <typename T>
void mergeInsterFJ(T &_container, int _level)
{
	/* STEP 1 : PAIRS */

	typedef typename T::iterator Iter;

	int pair_nb = _container.size() / _level;
	if (pair_nb < 2)
		return ;

	bool isOdd = pair_nb % 2 == 1;

	Iter it_start = _container.begin();
	Iter it_last = getNextIt(_container.begin(), _level * pair_nb);
	Iter it_end = getNextIt(it_last, -(isOdd * _level));
	int jump_size = 2 * _level;

	for (Iter it = it_start; it != it_end; std::advance(it, jump_size))
	{
		Iter pair_one = getNextIt(it, _level - 1);
		Iter pair_two = getNextIt(it, _level * 2 - 1);
		if (ft_comp(pair_two, pair_one))
			ft_swap(pair_one, _level);
	}

	// RECURSIVE
	mergeInsterFJ(_container, _level * 2);

	//printArray(_container, _level);

	/* STEP 2 : MAIN & PEND */

	std::vector<Iter> main;
	std::vector<Iter> pend;

	// INIT

	main.insert(main.end(), getNextIt(_container.begin(), _level - 1));
	main.insert(main.end(), getNextIt(_container.begin(), _level * 2 - 1));

	for (int i = 4; i <= pair_nb; i += 2)
	{
		pend.insert(pend.end(), getNextIt(_container.begin(), _level * (i - 1) - 1)); //Fill pend
		main.insert(main.end(), getNextIt(_container.begin(), _level * i - 1)); //Fill main
	}
	if (isOdd)
		pend.insert(pend.end(), getNextIt(it_end, _level - 1)); //Add last element if odd

	/* STEP 3.1 : JACOBSTHAL INSERTION */

	int prev_jacob = get_jacobsthal(1);
	int nb_to_insert = 0;

	for (int k = 2 ; true; k++)
	{
		int curr_jacob = get_jacobsthal(k);
		int diff_jacob = curr_jacob - prev_jacob;
		int offset = 0;
		if (diff_jacob > static_cast<int>(pend.size()))
			break;
		int nb_time = diff_jacob;

		typename std::vector<Iter>::iterator pend_it = getNextIt(pend.begin(), diff_jacob - 1);
		typename std::vector<Iter>::iterator bound_it = getNextIt(main.begin(), curr_jacob + nb_to_insert);

		while (nb_time)
		{
			typename std::vector<Iter>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, ft_comp<Iter>);
			typename std::vector<Iter>::iterator inserted = main.insert(idx, *pend_it);
			nb_time--;

			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);

			offset += (inserted - main.begin()) == curr_jacob + nb_to_insert;
			bound_it = getNextIt(main.begin(), curr_jacob + nb_to_insert - offset);
		}
		prev_jacob = curr_jacob;
		nb_to_insert += diff_jacob;
	}

	/* STEP 3.2 : INSERT REMAINING */

	for (ssize_t i = pend.size() - 1; i >= 0; i--)
	{
		typename std::vector<Iter>::iterator curr_pend = getNextIt(pend.begin(), i);
		typename std::vector<Iter>::iterator curr_bound = getNextIt(main.begin(), main.size() - pend.size() + i + isOdd);
		typename std::vector<Iter>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, ft_comp<Iter>);
		main.insert(idx, *curr_pend);
	}

	/* STEP 4 : FINAL OUTPUT */

	std::vector<int> copy;
	copy.reserve(_container.size());
	for (typename std::vector<Iter>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < _level; i++)
		{
			Iter start = *it;
			std::advance(start, -_level + i + 1);
			copy.insert(copy.end(), *start);
		}
	}

	Iter container_it = _container.begin();
	std::vector<int>::iterator copy_it = copy.begin();
	while (copy_it != copy.end())
	{
		*container_it = *copy_it;
		container_it ++;
		copy_it ++;
	}
}

#endif
