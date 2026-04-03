.PHONY: all clean fclean re printf
.DEFAULT_GOAL: all

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
LIB = libftprintf.a

SRC = \
		stack_ops.c \
		reverse_rotate.c \
		rotate.c \
		stack_behavior.c \
		algo_selection.c \
		selection_sort.c \
		chunk_sort.c \
		main_testing_chunk.c

OBJ = $(SRC:.c=.o)
AR = ar rcs

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -lm -o $(NAME)

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

re: fclean all
