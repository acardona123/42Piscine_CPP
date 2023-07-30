#include "PhoneBook.hpp"

int main()
{
	PhoneBook 	book;
	std::string	line;

	std::cout << "Phone book ready to be used." << std::endl;
	while (1)
	{
		getline(std::cin, line);
		if (!line.compare("ADD"))
			book.phonebook_add();
		else if (!line.compare("SEARCH"))
			book.phonebook_search();
		else if (!line.compare("EXIT"))
			return 0;
	}
}