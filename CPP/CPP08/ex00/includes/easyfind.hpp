#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception
{
	private:
	std::string m_message;

	public:
	NotFoundException(const char * _msg) : m_message(_msg) {}
	virtual ~NotFoundException() throw() {}
	virtual const char * what() const throw() {return (m_message.c_str());};
};

template<typename T>
typename T::iterator easyfind(T &_container, int _toFind)
{
	typename T::iterator it;

	it = std::find(_container.begin(), _container.end(), _toFind);
	if (it == _container.end())
		throw (NotFoundException("Element not found in container !"));
	return (it);
}
#endif
