LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
NAME		= push_swap
INC			= -I.

SRCS		= \
			src/main.c \
			src/parse/parse.c \
			src/parse/parse_helper.c \
			src/sort/sort.c \
			src/sort/sort_helper.c \
			src/sort/rules.c \
			src/sort/rules_helper.c \
			src/compress_data.c \
			src/exit_error.c \
			src/utils.c

OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) libft_copy
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)

libft_copy: $(LIBFT)
	cp $(LIBFT) ./libft.a

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f libft.a
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft_copy
