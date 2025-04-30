#include <algorithm>
#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int _size)
{
	m_size = _size;
}

Span::Span(const Span& _other)
{
	m_container.clear();
	for (std::vector<int>::const_iterator it = _other.m_container.begin(); it != _other.m_container.end(); it++)
	{
		m_container.push_back((*it));
	}
}

Span& Span::operator=(const Span& _other)
{
	if (this != &_other)
	{
		m_container.clear();
		for (std::vector<int>::const_iterator it = _other.m_container.begin(); it != _other.m_container.end(); it++)
		{
			m_container.push_back((*it));
		}
	}
	return (*this);
}

Span::~Span()
{
	m_container.clear();
}

void Span::addNumber(int _toAdd)
{
	if (m_container.size() < m_size)
		m_container.push_back(_toAdd);
	else
		throw(Span::ContainerSizeReachedException("Container is full !"));
}

void Span::addNumber(std::vector<int>::iterator _begin, std::vector<int>::iterator _end)
{
	if (m_container.size() + std::distance(_begin,_end) <= m_size)
		m_container.insert(m_container.end(), _begin ,_end);
	else
		throw(Span::ContainerSizeReachedException("Container would overflow !"));
}

unsigned int Span::shortestSpan(void)
{
	if (m_container.size() < 2)
		throw(Span::NotEnoughItemsException("Not enough items in container !"));
	std::vector<int> copy = m_container;
	std::sort(copy.begin(), copy.end());
	int min = copy[1] - copy[0];
	for(std::vector<int>::const_iterator it = copy.begin(); it + 1 != copy.end() - 1; it++)
	{
		if (*(it + 1) - (*it) < min)
		{
			min = *(it + 1) - (*it);
		}
	}
	return (min);
}

unsigned int Span::longestSpan(void)
{
	if (m_container.size() < 2)
		throw(Span::NotEnoughItemsException("Not enough items in container !"));
	std::vector<int>::iterator min = std::min_element(m_container.begin(), m_container.end());
	std::vector<int>::iterator max = std::max_element(m_container.begin(), m_container.end());
	return ((*max) - (*min));
}

//EXCEPTIONS

Span::ContainerSizeReachedException::ContainerSizeReachedException(const char *_msg)
: m_message(_msg)
{
}

Span::ContainerSizeReachedException::~ContainerSizeReachedException() throw() {}

Span::NotEnoughItemsException::NotEnoughItemsException(const char *_msg)
: m_message(_msg)
{
}

Span::NotEnoughItemsException::~NotEnoughItemsException() throw() {}

const char *Span::NotEnoughItemsException::what() const throw()
{
	return (m_message.c_str());
}

const char *Span::ContainerSizeReachedException::what() const throw()
{
	return (m_message.c_str());
}
