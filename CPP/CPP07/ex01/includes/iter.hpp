#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void	iter(T* _array, std::size_t _len, void(*f)(T &))
{
	for(std::size_t i = 0; i < _len; i++)
	{
		f(_array[i]);
	}
}

template <typename T>
void	iter(T* _array, std::size_t _len, void(*f)(T const&))
{
	for(std::size_t i = 0; i < _len; i++)
	{
		f(_array[i]);
	}
}
#endif
