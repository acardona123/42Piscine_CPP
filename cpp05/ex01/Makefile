NAME		=	ex01_executable

CC			=	c++
CFLAGS		=	-std=c++98 -Werror -Wall -Wextra -g
DEPSFLAG	=	-MMD

FILES		=	main \
				Bureaucrat \
				Form

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
	./$(NAME)

test : all
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes -s ./$(NAME)

-include $(DEPS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(DEPSFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPSFLAG) -c $< -o $@

.PHONY : all clean fclean re
