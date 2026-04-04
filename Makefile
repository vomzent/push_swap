.PHONY: all clean fclean re printf
.DEFAULT_GOAL: re

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
LIB = libftprintf.a
LIB2 = libft.a

SRC = \
		stack_ops.c \
		reverse_rotate.c \
		rotate.c \
		stack_behavior.c \
		algo_selection.c \
		selection_sort.c \
		chunk_sort.c \
		doubletest.c

OBJ = $(SRC:.c=.o)
AR = ar rcs

all: $(NAME)

$(NAME): $(LIB) $(LIB2) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -lft -lm -o $(NAME)


libft: $(LIB2)
$(LIB2):
	$(MAKE) -C libft
	cp libft/libft.a $(LIB2)

printf: $(LIB)
$(LIB):
	$(MAKE) -C ft_printf
	cp ft_printf/libftprintf.a $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	$(MAKE) fclean -C ft_printf
	$(MAKE) fclean -C libft

re: fclean all
