#include <iostream>

class Contact
{
public:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string darkest_secret;
};

class PhoneBook
{
public:
	int contact_count;
	Contact contacts[8];

	void add_contact(Contact contact)
	{
		if (contact_count < 8)
		{
			contacts[contact_count] = contact;
			contact_count++;
		}
		else
			contacts[0] = contact;
	}
	
	void search_contact()
	{
		char line[44];

		for (int i = 0; i < 44; i++)
		{
			line[i] = ' ';
		}
		line[44] = '\0';
		line[10] = '|';
		line[21] = '|';
		line[32] = '|';
		for (int i = 0; i < contact_count; i++)
		{
			if (i == 9)
			{
				line[8] = '1';
				line[9] = '0';
			}
			else
			{
				line[9] = i + 1 + '0';
				if (contact[i])
			}
		}
		std::cout << line << std::endl;
	}
};


int main()
{
	Contact contact;
	PhoneBook phonebook;

	phonebook.contact_count = 0;
	contact.firstname = "John";
	contact.lastname = "Doe";
	contact.nickname = "JD";
	contact.phone = "1234567890";
	contact.darkest_secret = "I am Batman";

	phonebook.add_contact(contact);
	phonebook.search_contact();
	return 0;
}
