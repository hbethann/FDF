NAME = fdf

CC = cc

FLAGS = -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -g

SRCS = main.c	draw.c	key.c	menu.c	read_file.c\
										libft/libft.a\

BONUS_SRCS = main_bonus.c	draw.c	key_bonus.c	 menu.c	read_file.c\
														libft/libft.a\

RM = rm -rf

.PHONY: all bonus clean fclean re


$(NAME):
	make all -C minilibx_macos
	make all -C libft
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

bonus :
	make clean
	make all -C minilibx_macos
	make all -C libft
	$(CC) $(FLAGS) $(BONUS_SRCS) -o $(NAME)

all: $(NAME)

fclean : clean
	$(RM) $(NAME)
	make clean -C minilibx_macos
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C minilibx_macos
	make clean -C libft

re : fclean all