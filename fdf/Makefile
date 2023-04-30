NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

MLX_DIR = mlx_linux
MLX_LIB = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11
MLX_INC = -I $(MLX_DIR)

MATH_LIB = -lm

SRC = fdf.c get_data.c display_data.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MATH_LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
