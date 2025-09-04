#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <string>

class Span
{
	public:
	Span();
	Span(unsigned int _size);
	Span(const Span& _other);
	Span& operator=(const Span& _other);
	~Span();

	void			addNumber(int _toAdd);
	void			addNumber(std::vector<int>::iterator _begin, std::vector<int>::iterator _end);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	private:
	unsigned int 		m_size;
	std::vector<int>	m_container;

	class ContainerSizeReachedException : public std::exception
	{
		private:
		std::string m_message;

		public:
		ContainerSizeReachedException(const char * _msg);
		virtual ~ContainerSizeReachedException() throw();
		virtual const char * what() const throw();

	};
	class NotEnoughItemsException : public std::exception
	{
		private:
		std::string m_message;

		public:
		NotEnoughItemsException(const char * _msg);
		virtual ~NotEnoughItemsException() throw();
		virtual const char * what() const throw();

	};
};

#endif
