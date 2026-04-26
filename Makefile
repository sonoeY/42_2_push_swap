LIBFT		= libft/libft.a
NAME		= push_swap
INC			= -I.
SRCS		= \
			src/main.c \
			src/parse/parse.c \
			src/parse/parse_helper.c \
			src/sort/sort.c \
			src/sort/sort_helper.c \
			src/sort/operations.c \
			src/sort/operations_helper.c \
			src/compression.c \
			src/exit_error.c \
			src/utils.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
