NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC := child1.c child2.c find_cmd_path.c main.c error.c
OBJ := $(SRC:.c=.o)

LIBFT_DIR = ./libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(LIBFT_LIB): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

clean : 
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -s fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

FORCE:

.PHONY : all clean fclean re
