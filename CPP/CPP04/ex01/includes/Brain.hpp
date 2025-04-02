#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	public:
	Brain();
	Brain(const Brain& _other);
	Brain& operator=(const Brain& _other);
	~Brain();

	private:
	std::string m_ideas[100];
};

#endif
