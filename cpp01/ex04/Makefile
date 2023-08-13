NAME		=	sedIsForLoosers

CC			=	c++
CFLAGS		=	-Werror -Wall -Wextra -std=c++98
DEPSFLAG	=	-MMD

FILES		=	main
				

SRC			=	$(addsuffix .cpp, $(FILES))

OBJ_DIR		=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:=.o))
DEPS		=	$(addprefix $(OBJ_DIR)/, $(FILES:=.d))

all : $(NAME)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

-include $(DEPS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(DEPSFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp  Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPSFLAG) -c $< -o $@

test :	all
	echo "this is a short text. it contains the kewyword "this".\nWe try to change this by THIS.\nis it doable ?\n" > testInput
	@echo ""
	./$(NAME) testInput this THIS

.PHONY : all clean fclean re
