NAME		=	ex00_executable

CC			=	c++
CFLAGS		=	-std=c++98 -Werror -Wall -Wextra
DEPSFLAG	=	-MMD

FILES		=	main \
				Fixed

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

-include $(DEPS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(DEPSFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPSFLAG) -c $< -o $@

.PHONY : all clean fclean re
