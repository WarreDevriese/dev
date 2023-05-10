GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"



NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src/
SRC_FILES = fdf.c scaling.c data.c hooks.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HDR_DIR = ./inc/
HDR_FILES = fdf.h
HDR_INC = -I $(HDR_DIR)
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

LIBFT_DIR = ./libft/
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

MLX_DIR = ./mlx_linux/
MLX_LIB = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11
MLX_INC = -I $(MLX_DIR)

MATH_LIB = -lm

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ)
	@echo "Object files for fdf created"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MATH_LIB) -o $(NAME)
	@echo "$(BOLD)$(GREEN)$(NAME) program succesfully created!$(RESET_FORMAT)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(HDR_INC) $(MLX_INC) $(LIBFT_INC) -c $< -o $@ 
	@echo "Compiled: $*.o $(GREEN)[OK]$(RESET_FORMAT)"

$(LIBFT_LIB): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
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
