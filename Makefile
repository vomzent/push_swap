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
		parse_input.c \
		ft_atol.c \
		algo_selection.c \
		selection_sort.c \
		input_test.c
		# doubletest.c

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
$(LIB): $(LIB2)
	$(MAKE) -C ft_printf
	cp ft_printf/libftprintf.a $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ft_printf
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	rm -f $(LIB2)
	$(MAKE) fclean -C ft_printf
	$(MAKE) fclean -C libft

re: fclean all

vincenttest: $(LIB) $(LIB2) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -g -L. -lftprintf -lft -lm vincent_basic_stackopstest.c
