NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC := main.c parse.c stacks.c operations.c cases.c sort_phase1.c sort_phase2.c sort_small.c
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
	$(MAKE) -C $(LIBFT_DIR)

clean : 
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -s fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all

FORCE:

.PHONY : all clean fclean re
