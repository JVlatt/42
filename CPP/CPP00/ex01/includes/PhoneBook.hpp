#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#ifndef MAX_SIZE
#define MAX_SIZE 8
#endif

#include "Contact.hpp"

class PhoneBook
{
private:
	int m_last;

public:
	Contact contacts[MAX_SIZE];
	PhoneBook();
	~PhoneBook();
	void	AddContact(Contact _newContact);
	int		GetContactsNb();
};

#endif
