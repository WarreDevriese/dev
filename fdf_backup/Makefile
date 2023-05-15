GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC_FILES = fdf.c scaling.c data.c hooks.c
OBJ_FILES = $(SRC_FILES:.c=.o)

HDR_FILES = fdf.h

LIBFT_DIR = ./libft/
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

MLX_DIR = ./mlx_linux/
MLX_LIB = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11
MLX_INC = -I $(MLX_DIR)

MATH_LIB = -lm

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ_FILES)
	@echo "Object files for fdf created"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LIB) $(MLX_LIB) $(MATH_LIB) -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(NAME) program succesfully created!$(RESET_FORMAT)"

%.o: %.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -c $< -o $@ 
	@echo "Compiled: $*.o $(GREEN)[OK]$(RESET_FORMAT)"

$(LIBFT_LIB): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ_FILES)
	@echo "Object files related to $(NAME) deleted"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@echo "$(NAME) program deleted"
	@echo "$(BOLD)$(GREEN)$(NAME) folder is clean!$(RESET_FORMAT)"

re:
	@$(MAKE) clean
	@echo ""
	@$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
