.PHONY: fclean clean all re
.DEFAULT_GOAL = all

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = \
	ft_isdigit.c \
	ft_bzero.c \
	ft_strncmp.c \
	ft_itoa.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_split.c
OBJ = $(SRC:.c=.o)
AR = ar rcs

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