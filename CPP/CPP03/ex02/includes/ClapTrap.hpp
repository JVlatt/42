#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& _other);
	ClapTrap& operator=(const ClapTrap& _other);
	~ClapTrap();

	virtual void 	attack(const std::string& _target);
	void 			takeDamage(unsigned int _amount);
	void 			beRepaired(unsigned int _amount);

	protected:
	std::string		m_name;
	unsigned int	m_hp;
	unsigned int	m_energy;
	unsigned int	m_attack;
};

#endif
