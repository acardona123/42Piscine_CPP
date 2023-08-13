NAME		=	brain

CC			=	c++
CFLAGS		=	-Werror -Wall -Wextra -std=c++98

FILES		=	main

SRC			=	$(addsuffix .cpp, $(FILES))

OBJ_DIR		=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:=.o))
DEPS_DIR	=	dep
DEPS		=	$(addprefix $(DEPS_DIR)/, $(FILES:=.d))

all : $(NAME)

clean :
	rm -rf $(DEPS_DIR) $(OBJ_DIR) $(NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# -include $(DEPS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


$(DEPS_DIR)/%.d : %.cpp
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) -MM -MT '$(OBJ_DIR)/$(notdir $(patsubst %.cpp, %.o, $<))' $< -MF $@

$(OBJ_DIR)/%.o : %.cpp 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@




.PHONY : all clean fclean re
