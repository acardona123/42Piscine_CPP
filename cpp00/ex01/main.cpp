#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	book;
	std::string	line;

	while (1)
	{
		std::cout << std::endl << "Command (ADD, SEARCH or EXIT): ";
		getline(std::cin, line);
		if (!line.compare("ADD"))
			book.phonebook_add();
		else if (!line.compare("SEARCH"))
			book.phonebook_search();
		else if (!line.compare("EXIT"))
			return 0;
		else
		 	std::cout << "  command unknown" << std::endl;
	}
}