
NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = minitalk.h
FILES = ft_printf.c ft_putnbr.c ft_putchar.c ft_putstr.c ft_optimize.c\
		ft_tools.c ft_strjoin.c ft_calloc.c
OBG = $(FILES:.c=.o)

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

all:$(NAME)

$(NAME):$(OBG)
	ar rc $(NAME) $(OBG)

clean:
	rm -f $(OBG) $(OBGB)

fclean: clean
	rm -f $(NAME) client server

re: fclean all

run:
	make re
	cc client.c minitalk.a -o client
run2:
	make re
	cc server.c minitalk.a -o server
.PHONY: all clean fclean re run run2