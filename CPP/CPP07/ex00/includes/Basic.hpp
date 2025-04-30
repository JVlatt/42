#ifndef BASIC_HPP
#define BASIC_HPP

template <typename T>
void swap(T &A,T &B)
{
	T tmp = A;
	A = B;
	B = tmp;
}

template <typename T>
T min(T const &A,T const &B )
{
	if (A < B)
		return (A);
	else
		return (B);
}

template <typename T>
T max(T const &A,T const &B)
{
	if (A > B)
		return (A);
	else
		return (B);
}

#endif
