NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
SRC = ft_printf.c ft_printf_utils.c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re