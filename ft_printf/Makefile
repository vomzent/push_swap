.PHONY: all clean fclean re
.DEFAULT_GOAL: all

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = \
		check_percent.c \
		convert_arg.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_putnbr_u.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_printf.c
OBJ = $(SRC:.c=.o)
AR = ar rcs
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all