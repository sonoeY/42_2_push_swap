# LIBFT = libft/libft.a
LIBFT 		= 42_0_libft/libft.a
NAME		= push_swap
LIB_PS		= libft_ps.a
MAIN 		= main.c
SRCS		= parse.c parse_helper.c sort_rules.c utils.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(MAIN) $(LIB_PS)
	$(CC) $(CFLAGS) $(MAIN) $(LIB_PS) -o $(NAME)

$(LIB_PS): $(OBJS) $(LIBFT)
	cp -f $(LIBFT) $(LIB_PS)
	ar rcs $(LIB_PS) $(OBJS)

$(LIBFT):
	make -C 42_0_libft
# 	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB_PS)
	make -C 42_0_libft fclean
# 	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
