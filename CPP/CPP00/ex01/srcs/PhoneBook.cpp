#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_last = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact(Contact _newContact)
{
	if (m_last >= MAX_SIZE)
		m_last = 0;
	contacts[m_last] = _newContact;
	m_last++;
}

int PhoneBook::GetContactsNb()
{
	int	count = 0;

	for (int i = 0; i < MAX_SIZE; ++i)
	{
		if (!contacts[i].getFirstName().empty())
			count ++;
	}
	return (count);
}
