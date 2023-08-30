#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	book;
	std::string	line;

	while (1)
	{
		std::cout << std::endl << "Command (ADD, SEARCH or EXIT): ";
		getline(std::cin, line);
		if (std::cin.bad() || std::cin.eof())
		{
			std::cout << std::endl << INPUT_ERROR_MSG << std::endl;
			return (1);
		}
		if (!line.compare("ADD"))
		{
			if (book.phonebook_add())
				return (0);
		}
		else if (!line.compare("SEARCH"))
		{
			if (book.phonebook_search())
				return (0);
		}
		else if (!line.compare("EXIT"))
			return 0;
		else
		 	std::cout << "  command unknown" << std::endl;
	}
}