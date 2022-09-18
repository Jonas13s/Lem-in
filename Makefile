NAME = lem-in

LEM_IN_SRC = lines.c rooms.c utils.c ants.c check.c
LEM_IN_DIR = ./src/
LEM_IN_OBJ_LIST = $(addprefix $(OBJ_DIR), $(LEM_IN_SRC:.c=.o))

LEM_IN_NAME = lem_in.c
LEM_IN_OBJ = $(addprefix $(OBJ_DIR), $(LEM_IN_NAME:.c=.o))

OBJ_DIR = obj/

HEADERS_LIST = lem_in.h errors.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

INCLUDES = -I includes/ -I libft/

LINK = -lft -L libft/

FLAGS = -Wall -Wextra -Werror

CC = gcc

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(LEM_IN_OBJ) $(LEM_IN_OBJ_LIST)
	@$(CC) $(FLAGS) $(LEM_IN_OBJ) $(LEM_IN_OBJ_LIST) -o $(NAME) $(LINK) $(INCLUDES)
	@echo "$@ compiled"
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)$(OBJ_DIR) created$(RESET)"

$(OBJ_DIR)%.o : $(LEM_IN_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN)compiling $<$(RESET)"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(GREEN)$(LIBFT_DIR) compiled$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft/ clean
fclean: clean
	@rm -rf $(NAME)
	@make -s -C libft/ fclean
re: fclean all