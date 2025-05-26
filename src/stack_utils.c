/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:22 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:22 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_new(t_push_swap *ps, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		if (ps->data->argc == 2)
			free_2d(ps->data->input);
		free(ps->data->numbers);
		free(ps->data);
		free(ps);
		print_error();
	}
	ft_memset(new, 0, sizeof(t_stack));
	new->value = value;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!*stack)
		*stack = new;
	else
	{
		tmp = stack_last(*stack);
		tmp->next = new;
	}
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

int	stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
