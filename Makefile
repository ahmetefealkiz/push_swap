NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_PATH = src/
OBJS_PATH = objs/

LIBFT = ./lib/Libft/libft.a 
FT_PRINTF = ./lib/ft_printf/libftprintf.a

SRC		=	main.c utils.c check_data.c check_data_utils.c stack_init.c stack_utils.c \
			handle_free.c operations_push.c operations_swap.c operations_rotate.c \
			operations_rev_rotate.c sort_utils.c sort.c set_stack.c sort_a_to_b.c sort_b_to_a.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C lib/Libft

$(FT_PRINTF):
	@make -C lib/ft_printf

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

clean:
	@cd lib/Libft && make clean
	@cd lib/ft_printf && make clean
	@rm -f $(OBJS)

fclean:  clean
	@cd lib/Libft && make fclean
	@cd lib/ft_printf && make fclean
	@rm -f $(NAME)

re: fclean all