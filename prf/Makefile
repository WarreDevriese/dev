CC = cc
AR = ar
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs

NAME = libftprintf.a
SRC := ft_printf.c ft_printf_utils.c handle_cspercent.c handle_id.c handle_u.c handle_xXp.c
OBJ := $(SRC:.c=.o)

.PHONY : all clean fclean re
all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
