NAME		=	ex02.exe

CC			=	cerror: no matching constructor for initialization of 'MutantStack<int>::iterator'
                MutantStack<int>::iterator it (mstack.begin());++
CFLAGS		=	-Werror -Wall -Wextra -g
DEPSFLAG	=	-MMD

FILES		=	main \

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

run : all
	./$(NAME) $(ARGS)

test : all
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes -s ./$(NAME)

-include $(DEPS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(DEPSFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPSFLAG) -c $< -o $@

.PHONY : all clean fclean re
