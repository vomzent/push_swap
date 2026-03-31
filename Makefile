.PHONY: all clean fclean re
.DEFAULT_GOAL: all

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = \
		stack_ops.c \
		stack_behavior.c \
		main_testing.c
OBJ = $(SRC:.c=.o)
AR = ar rcs
NAME = push_swap
LIB = libftprintf.a

all: $(NAME)

$(NAME): printf $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lftprintf -o $(NAME)

printf: 
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