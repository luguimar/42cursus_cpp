#include <iostream>
#include <string>

int ft_has_only_digits(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

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
	
	int search_contact()
	{
		char line[44];

		for (int i = 0; i < contact_count; i++)
		{
			for (int i = 0; i < 44; i++)
			{
				line[i] = ' ';
			}
			line[44] = '\0';
			line[10] = '|';
			line[21] = '|';
			line[32] = '|';
			if (i == 9)
			{
				line[8] = '1';
				line[9] = '0';
			}
			else
				line[9] = i + 1 + '0';
			if (contacts[i].firstname.length() > 10)
			{
				for (int j = 0; j < 9; j++)
				{
					line[j + 11] = contacts[i].firstname[j];
				}
				line[20] = '.';
			}
			else
			{
				for (int j = contacts[i].firstname.length() - 1; j >= 0; j--)
				{
					line[20 - j] = contacts[i].firstname[j];
				}
			}
			if (contacts[i].lastname.length() > 10)
			{
				for (int j = 0; j < 9; j++)
				{
					line[j + 22] = contacts[i].lastname[j];
				}
				line[31] = '.';
			}
			else
			{
				for (int j = contacts[i].lastname.length() - 1; j >= 0; j--)
				{
					line[31 - j] = contacts[i].lastname[j];
				}
			}
			if (contacts[i].nickname.length() > 10)
			{
				for (int j = 0; j < 9; j++)
				{
					line[33 - j] = contacts[i].nickname[j];
				}
				line[42] = '.';
			}
			else
			{
				for (int j = contacts[i].nickname.length() - 1; j >= 0; j--)
				{
					line[42 - j] = contacts[i].nickname[j];
				}
			}
			std::cout << line << std::endl;
		}
		std::cout << "Enter the index of the contact: ";
		int index;
		std::string line1;
		if (std::getline(std::cin, line1))
		{
			if (line1[1] == '\0' && line1[0] >= '0' && line1[0] <= '9')
				index = line1[0] - '0';
			else if (std::cin.eof())
				return 1;
			else
			{
				std::cout << "Invalid Index." << std::endl;
				return 0;
			}
		}
		else if (std::cin.eof())
			return 1;
		else
		{
			std::cout << "Invalid index." << std::endl;
			return 0;
		}
		if (index > 0 && index <= contact_count)
		{
			std::cout << "First name: " << contacts[index - 1].firstname << std::endl;
			std::cout << "Last name: " << contacts[index - 1].lastname << std::endl;
			std::cout << "Nickname: " << contacts[index - 1].nickname << std::endl;
			std::cout << "Phone number: " << contacts[index - 1].phone << std::endl;
			std::cout << "Darkest secret: " << contacts[index - 1].darkest_secret << std::endl;
		}
		else
			std::cout << "Invalid index." << std::endl;
		return 0;
	}
};

int main()
{
	PhoneBook phonebook;
	Contact contact;

	phonebook.contact_count = 0;

	while (1)
	{
		std::string command;
		std::cout << "Enter a command: ";
		if (std::getline(std::cin, command))
			;
		else if (std::cin.eof())
			break;
		else
		{
			std::cout << "Invalid command." << std::endl;
			continue;
		}
		if (command == "ADD" || command == "SEARCH" || command == "EXIT")
			;
		else
		{
			std::cout << "Invalid command." << std::endl;
			continue;
		}
		if (command == "ADD")
		{
			std::cout << "Enter the first name: ";
			if (std::getline(std::cin, contact.firstname) && contact.firstname.length() > 0)
				;
			else if (std::cin.eof())
				break;
			else
			{
				std::cout << "Invalid first name." << std::endl;
				continue;
			}
			std::cout << "Enter the last name: ";
			if (std::getline(std::cin, contact.lastname))
				;
			else if (std::cin.eof())
				break;
			else
			{
				std::cout << "Invalid last name." << std::endl;
				continue;
			}
			std::cout << "Enter the nickname: ";
			if (std::getline(std::cin, contact.nickname) && contact.nickname.length() > 0)
				;
			else if (std::cin.eof())
				break;
			else
			{
				std::cout << "Invalid nickname." << std::endl;
				continue;
			}
			std::cout << "Enter the phone number: ";
			if (std::getline(std::cin, contact.phone) && contact.phone.length() > 0 && ft_has_only_digits(contact.phone))
				;
			else if (std::cin.eof())
				break;
			else
			{
				std::cout << "Invalid phone number." << std::endl;
				continue;
			}
			std::cout << "Enter the darkest secret: ";
			if (std::getline(std::cin, contact.darkest_secret) && contact.darkest_secret.length() > 0)
				;
			else if (std::cin.eof())
				break;
			else
			{
				std::cout << "Invalid darkest secret." << std::endl;
				continue;
			}
			phonebook.add_contact(contact);
		}
		else if (command == "SEARCH")
		{
			if (phonebook.contact_count == 0)
			{
				std::cout << "No contacts." << std::endl;
				continue;
			}
			if (phonebook.search_contact())
				break;
		}
		else if (command == "EXIT")
			break;
	}
	return 0;
}
