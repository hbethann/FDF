NAME= libft.a

SRCS= *.c  

OBJECTS= *.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	cc -Wall -Wextra -Werror -c $(SRCS) -I $(HEDER)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all