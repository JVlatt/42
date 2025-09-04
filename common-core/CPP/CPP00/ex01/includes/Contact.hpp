#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickName;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;

public:
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();

	void	setFirstName(std::string _firstName);
	void	setLastName(std::string _lastName);
	void	setNickName(std::string _nickName);
	void	setPhoneNumber(std::string _phoneNumber);
	void	setDarkestSecret(std::string _darkestSecret);
};

#endif
