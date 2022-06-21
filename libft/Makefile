NAME=libft.a

SRCS=*.c  

OBJECTS=*.o

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -c $(SRCS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all