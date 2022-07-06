NAME = fdf
CC = cc
FLAGS = -Wall -Wextra -Werror
FRAMEWOK = -framework OpenGL -framework AppKit
SRCS = main.c	draw.c	key.c	menu.c	read_file.c\

BONUS_SRCS = main_bonus.c	draw.c	key_bonus.c	 menu.c	read_file.c\

INCL = fdf.h 

LIBFT_DIR = libft

LIBFT_MAKE = cd $(LIBFT_DIR) && make

LIBFT_INC = -L $(LIBFT_DIR) -lft

OBJS = $(SRCS:.c = .o)

OBJS_BONUS = $(BONUS_SRCS:.c = .o)

.PHONY: all bonus clean fclean re

all: $(NAME)

%.o: %.c $(INCL)
	@$(CC) $(FLAGS) -I $(INCL) -c $< -o $@

$(NAME): $(OBJS) $(INCL)
	@$(CC) $(FLAGS) $(OBJS) -lmlx $(FRAMEWOK) $(LIBFT_INC) -o $(NAME)

bonus: $(OBJS_BONUS) $(INCL)
	@$(CC) $(FLAGS) $(OBJS_BONUS) $(FRAMEWOK) $(LIBFT_INC) -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o

fclean: clean
	@rm -rf *.a
	@rm -rf fdf

re: fclean clean


