NAME		=	phonebook

CC			=	c++
CFLAGS		=	-Werror -Wall -Wextra -std=c++98

FILES		=	Contact PhoneBook main
INCLUDES	=	Contact.hpp Phonebook.hpp

DEPS		=	$(INCLUDES) Makefile

SRC			=	$(FILES:=.cpp)

OBJ_DIR		=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
