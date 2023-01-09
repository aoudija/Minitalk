
NAME = minitalk.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = minitalk.h
FILES = ft_tools.c ft_strjoin.c ft_tools2.c ft_tools3.c
OBG = $(FILES:.c=.o)

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

all:$(NAME)

$(NAME):$(OBG)
	ar rc $(NAME) $(OBG)

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME) client server

re: fclean all

client: all
	rm -rf client
	cc client.c minitalk.a -o client
server: all
	rm -rf server
	cc server.c minitalk.a -o server
.PHONY: all clean fclean re client server