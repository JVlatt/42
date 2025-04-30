#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	public:
	Span();
	Span(unsigned int _size);
	Span(const Span& _other);
	Span& operator=(const Span& _other);
	~Span();

	void			addNumber(int _toAdd);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	private:
	unsigned int 		m_size;
	std::vector<int>	m_container;
};

#endif
