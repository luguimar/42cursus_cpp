#include <iostream>
#include <string>
#include <cctype>

int hasNonPrintableCharacters(const std::string& str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (!isprint(str[i])) {
            return 1;
        }
    }
    return 0;
}

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
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string darkest_secret;

public:
    std::string get_firstname()
    {
        return firstname;
    }
    std::string get_lastname()
    {
        return lastname;
    }
    std::string get_nickname()
    {
        return nickname;
    }
    std::string get_phone()
    {
        return phone;
    }
    std::string get_darkest_secret()
    {
        return darkest_secret;
    }
    void set_firstname(std::string firstname)
    {
        this->firstname = firstname;
    }
    void set_lastname(std::string lastname)
    {
        this->lastname = lastname;
    }
    void set_nickname(std::string nickname)
    {
        this->nickname = nickname;
    }
    void set_phone(std::string phone)
    {
        this->phone = phone;
    }
    void set_darkest_secret(std::string darkest_secret)
    {
        this->darkest_secret = darkest_secret;
    }
};

class PhoneBook
{
private:
	Contact contacts[8];
	int contact_count;
	int contact_rotations;
public:

    int get_contact_count()
    {
        return contact_count;
    }

    int get_contact_rotations()
    {
        return contact_rotations;
    }

    void set_contact_count(int contact_count)
    {
        this->contact_count = contact_count;
    }

    void set_contact_rotations(int contact_rotations)
    {
        this->contact_rotations = contact_rotations;
    }

	void add_contact(Contact contact)
	{
		if (contact_count < 8)
		{
			contacts[contact_count] = contact;
			contact_count++;
			contact_rotations++;
		}
		else
		{
			if (contact_rotations == 8)
				contact_rotations = 0;
			contacts[contact_rotations] = contact;
			contact_rotations++;
		}
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
			if (contacts[i].get_firstname().length() > 10)
			{
				for (int j = 0; j < 9; j++)
				{
					line[j + 11] = contacts[i].get_firstname()[j];
				}
				line[20] = '.';
			}
			else
			{
				for (int j = contacts[i].get_firstname().length() - 1; j >= 0; j--)
                {
                    line[20 - contacts[i].get_firstname().length() + j + 1] = contacts[i].get_firstname()[j];
                }
			}
			if (contacts[i].get_lastname().length() > 10)
            {
                for (int j = 0; j < 9; j++)
                {
                    line[j + 22] = contacts[i].get_lastname()[j];
                }
                line[31] = '.';
            }
            else
            {
                for (int j = contacts[i].get_lastname().length() - 1; j >= 0; j--)
                {
                    line[31 - contacts[i].get_lastname().length() + j + 1] = contacts[i].get_lastname()[j];
                }
            }
			if (contacts[i].get_nickname().length() > 10)
			{
				for (int j = 0; j < 9; j++)
				{
					line[33 + j] = contacts[i].get_nickname()[j];
				}
				line[42] = '.';
			}
			else
			{
				for (int j = contacts[i].get_nickname().length() - 1; j >= 0; j--)
				{
					line[42 - contacts[i].get_nickname().length() + j + 1] = contacts[i].get_nickname()[j];
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
			std::cout << "First name: " << contacts[index - 1].get_firstname() << std::endl;
            std::cout << "Last name: " << contacts[index - 1].get_lastname() << std::endl;
            std::cout << "Nickname: " << contacts[index - 1].get_nickname() << std::endl;
            std::cout << "Phone number: " << contacts[index - 1].get_phone() << std::endl;
            std::cout << "Darkest secret: " << contacts[index - 1].get_darkest_secret() << std::endl;
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
    std::string line;

    phonebook.set_contact_count(0);
    phonebook.set_contact_rotations(0);

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
			if (std::getline(std::cin, line) && !hasNonPrintableCharacters(line) && line.length() > 0)
                ;
            else if (std::cin.eof())
                break;
            else
            {
                std::cout << "Invalid first name." << std::endl;
                continue;
            }
            contact.set_firstname(line);
            std::cout << "Enter the last name: ";
            if (std::getline(std::cin, line) && !hasNonPrintableCharacters(line) && line.length() > 0)
                ;
            else if (std::cin.eof())
                break;
            else
            {
                std::cout << "Invalid last name." << std::endl;
                continue;
            }
            contact.set_lastname(line);
            std::cout << "Enter the nickname: ";
            if (std::getline(std::cin, line) && !hasNonPrintableCharacters(line) && line.length() > 0)
                ;
            else if (std::cin.eof())
                break;
            else
            {
                std::cout << "Invalid nickname." << std::endl;
                continue;
            }
            contact.set_nickname(line);
            std::cout << "Enter the phone number: ";
            if (std::getline(std::cin, line) && !hasNonPrintableCharacters(line) && line.length() > 0)
                ;
            else if (std::cin.eof())
                break;
            else
            {
                std::cout << "Invalid phone number." << std::endl;
                continue;
            }
            if (!ft_has_only_digits(line))
            {
                std::cout << "Invalid phone number." << std::endl;
                continue;
            }
            contact.set_phone(line);
            std::cout << "Enter the darkest secret: ";
            if (std::getline(std::cin, line) && !hasNonPrintableCharacters(line) && line.length() > 0)
                ;
            else if (std::cin.eof())
                break;
            else
            {
                std::cout << "Invalid darkest secret." << std::endl;
                continue;
            }
            contact.set_darkest_secret(line);
			phonebook.add_contact(contact);
		}
		else if (command == "SEARCH")
		{
			if (phonebook.get_contact_count() == 0)
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
