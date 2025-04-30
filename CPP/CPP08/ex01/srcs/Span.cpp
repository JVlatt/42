#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int _size)
{
}

Span::Span(const Span& _other)
{

}

Span& Span::operator=(const Span& _other)
{

}

Span::~Span()
{

}

void Span::addNumber(int _toAdd)
{
	if (m_container.size() < m_size)
		m_container.push_back(_toAdd);
	// else
	// 	throw();
}

unsigned int Span::shortestSpan(void)
{
	return 0;
}

unsigned int Span::longestSpan(void)
{
	return 0;
}
