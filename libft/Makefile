NAME	=	libft.a

SRCS	=	ft_atoi.c		ft_bzero.c				ft_calloc.c			ft_isalnum.c\
			ft_isalpha.c	ft_isascii.c			ft_isdigit.c		ft_isprint.c\
			ft_memchr.c		ft_memcmp.c				ft_memcpy.c			ft_memmove.c\
			ft_memset.c		ft_strchr.c				ft_strdup.c			ft_strjoin.c\
			ft_strlcat.c	ft_strlcpy.c			ft_strlen.c			ft_strncmp.c\
			ft_strnstr.c	ft_strrchr.c			ft_substr.c			ft_tolower.c\
			ft_toupper.c	ft_putnbr_fd.c			ft_putchar_fd.c		ft_putendl_fd.c\
			ft_substr.c		ft_strjoin.c			ft_putstr_fd.c		ft_strtrim.c\
			ft_strtrim.c	ft_itoa.c				ft_striteri.c		ft_strmapi.c\
			ft_split.c		get_next_line_utils.c	get_next_line.c		ft_lstsize.c\
			ft_lstnew.c		ft_lstmap.c				ft_lstlast.c		ft_lstiter.c\
			ft_lstdelone.c	ft_lstclear.c			ft_lstadd_front.c	ft_lstadd_back.c\


HEADER	=	libft.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I $(HEADER) -g

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rsc	$(NAME) $?

%.o		:	%.c	$(HEADER)
	$(CC)	$(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@$(RM) $(NAME)

re		: fclean all