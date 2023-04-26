NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

SRC = pipex.c child1.c child2.c find_cmd_path.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
