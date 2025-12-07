NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = commands1.c commands2.c commands3.c error_handling.c ft_split.c initialize.c main.c sort.c utils1.c utils2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
