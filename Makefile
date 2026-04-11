.PHONY: all clean fclean re printf
.DEFAULT_GOAL: re

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
LIB = libftprintf.a
LIB2 = libft.a

SRC = \
		stack_core.c \
		stack_core2.c \
		stack_ops.c \
		stack_ops_r.c \
		stack_ops_rr.c \
		utils.c \
		ft_atol.c \
		sort_base.c \
		parse_load.c \
		parse_args.c \
		parse_validate.c \
		benchmark.c \
		stack_utils.c \
		stack_utils2.c \
		selection_sort.c \
		chunk_utils.c \
		chunk_utils2.c \
		chunk_sort.c

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
