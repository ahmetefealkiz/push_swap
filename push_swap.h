/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:35 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/17 01:38:47 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/Libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost;
	int					above_median;
	struct s_stack		*target_node;
	struct s_stack		*next;
}						t_stack;

typedef struct s_data
{
	char				**input;
	int					size;
	int					argc;
	int					*numbers;
}						t_data;

typedef struct s_push_swap
{
	t_stack				*stack_a;
	t_stack				*stack_b;
	t_data				*data;
}						t_push_swap;

void					print_error(void);
void					free_2d(char **arr);
void					check_duplicate(t_push_swap *ps);
int						strlen_2d(char	**str);
long					atol(const char *str);
void					free_stack(t_stack *stack);
void					stack_init(t_push_swap *ps);
t_stack					*stack_new(t_push_swap *ps, int value);
t_stack					*stack_last(t_stack *stack);
void					stack_add_back(t_stack **stack, t_stack *new);
void					stack_add_front(t_stack **stack, t_stack *new);
int						stack_size(t_stack *stack);
void					set_target_a(t_push_swap *ps);
void					set_cost(t_push_swap *ps, t_stack *stack);
void					set_all(t_push_swap *ps);
int						is_sorted(t_stack	*stack);
void					sort_stack(t_push_swap *ps);
void					a_to_b(t_push_swap *ps);
void					b_to_a(t_push_swap *ps);
t_stack					*find_max(t_stack *stack);
t_stack					*find_target(t_stack *stack, int value);
void					order_stack_b(t_push_swap *ps);
void					order_stack_a(t_push_swap *ps);
void					sa(t_push_swap *ps, int print);
void					sb(t_push_swap *ps, int print);
void					ss(t_push_swap *ps);
void					pa(t_push_swap *ps);
void					pb(t_push_swap *ps);
void					ra(t_push_swap *ps, int print);
void					rb(t_push_swap *ps, int print);
void					rr(t_push_swap *ps);
void					rra(t_push_swap *ps, int print);
void					rrb(t_push_swap *ps, int print);
void					rrr(t_push_swap *ps);
void					check_long(t_push_swap *ps, char *str, char **free_str);
int						*alloc_numbers(t_push_swap *ps, int size);
int						count_spilted_input(int added_numbers,
							char **input_splitted);
int						count_input(t_push_swap *ps);
int						add_input(t_push_swap *ps, char **input_splitted,
							int added_numbers);
#endif