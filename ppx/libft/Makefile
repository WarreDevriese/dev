## FORMATTING

GREEN = "\\033[32m"
BOLD = "\\033[1m"
PINK = "\\033[95m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

## COMPILATION

NAME = libft.a
CC = cc
AR = ar
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs

## HEADERS

HDR_DIR = ./inc/
HDR_FILES = libft.h \
			get_next_line.h \
			ft_printf.h
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

## SOURCES

SRC_DIR = ./src/

SRC_FILES += char/ft_isalnum.c
SRC_FILES += char/ft_isalpha.c
SRC_FILES += char/ft_isascii.c
SRC_FILES += char/ft_isdigit.c
SRC_FILES += char/ft_isprint.c
SRC_FILES += char/ft_tolower.c
SRC_FILES += char/ft_toupper.c


SRC_FILES += conversion/ft_itoa.c
SRC_FILES += conversion/ft_atoi.c

SRC_FILES += math/ft_abs.c
SRC_FILES += math/ft_max.c
SRC_FILES += math/ft_min.c

SRC_FILES += io/ft_close.c
SRC_FILES += io/ft_open_rdonly.c
SRC_FILES += io/ft_putchar_fd.c
SRC_FILES += io/ft_putendl_fd.c
SRC_FILES += io/ft_putnbr_fd.c
SRC_FILES += io/ft_putstr_fd.c
SRC_FILES += io/get_next_line.c
SRC_FILES += io/get_next_line_utils.c

SRC_FILES += list/ft_lstadd_back.c
SRC_FILES += list/ft_lstadd_front.c
SRC_FILES += list/ft_lstclear.c
SRC_FILES += list/ft_lstdelone.c
SRC_FILES += list/ft_lstiter.c
SRC_FILES += list/ft_lstlast.c
SRC_FILES += list/ft_lstmap.c
SRC_FILES += list/ft_lstnew.c
SRC_FILES += list/ft_lstsize.c

SRC_FILES += memory/ft_bzero.c
SRC_FILES += memory/ft_calloc.c
SRC_FILES += memory/ft_memchr.c
SRC_FILES += memory/ft_memcmp.c
SRC_FILES += memory/ft_memcpy.c
SRC_FILES += memory/ft_memmove.c
SRC_FILES += memory/ft_memset.c
SRC_FILES += memory/ft_free_array.c

SRC_FILES += string/ft_split.c
SRC_FILES += string/ft_strchr.c
SRC_FILES += string/ft_strdup.c
SRC_FILES += string/ft_striteri.c
SRC_FILES += string/ft_strjoin.c
SRC_FILES += string/ft_strlcat.c
SRC_FILES += string/ft_strlcpy.c
SRC_FILES += string/ft_strlen.c
SRC_FILES += string/ft_strmapi.c
SRC_FILES += string/ft_strncmp.c
SRC_FILES += string/ft_strnstr.c
SRC_FILES += string/ft_strrchr.c
SRC_FILES += string/ft_strtrim.c
SRC_FILES += string/ft_substr.c
SRC_FILES += string/ft_word_count.c

SRC_FILES += ft_printf/ft_printf.c
SRC_FILES += ft_printf/ft_printf_conversions.c
SRC_FILES += ft_printf/ft_printf_utils.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

## OBJECT FILES

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ERASE_LINE)"
	@echo "Object files for libft created"
	@$(AR) $(ARFLAGS) $(NAME) $^
	@ranlib $(NAME)
	@echo "$(BOLD)$(GREEN)$(NAME) successfully created!$(RESET_FORMAT)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/char
	@mkdir -p $(OBJ_DIR)/conversion
	@mkdir -p $(OBJ_DIR)/math
	@mkdir -p $(OBJ_DIR)/io
	@mkdir -p $(OBJ_DIR)/list
	@mkdir -p $(OBJ_DIR)/memory
	@mkdir -p $(OBJ_DIR)/string
	@mkdir -p $(OBJ_DIR)/ft_printf
	@echo "$(BOLD)$(PINK)Compiling libft object files...$(RESET_FORMAT)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c $< -o $@ 

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files related to libft deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
	@echo "$(BOLD)$(GREEN)$(NAME) folder is clean!$(RESET_FORMAT)"

re:
	@$(MAKE) fclean
	@echo ""
	@$(MAKE) all

.PHONY: all clean fclean re
