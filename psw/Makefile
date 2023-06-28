NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC := main.c parse.c stacks.c operations.c cases.c sort.c sort1.c sort2.c

OBJ_DIR	:= ./obj/
OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR = ./libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
LIBFT_INC = -I $(LIBFT_DIR)

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

$(LIBFT_LIB): FORCE
	$(MAKE) -C $(LIBFT_DIR)

clean : 
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -s fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re : fclean all

FORCE:

.PHONY : all clean fclean re
