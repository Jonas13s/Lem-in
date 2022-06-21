OBJ_DIR = obj/

LIBFT = libft/libft.a

INCLUDES = -I includes/ -I libft/

LINK = -L libft/ -lft

FLAGS = -Wall -Wextra -Werror

all:
clean:
	@rm -rf $(OBJ_DIR)
	@make -s -C libft/ clean
fclean: clean
	@make -s -C libft/ fclean
re: fclean all