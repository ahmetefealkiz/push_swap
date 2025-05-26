/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:00 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:00 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calculate_cost(t_push_swap *ps, t_stack *stack)
{
	int		cost_a;
	int		cost_b;
	int		size_a;
	int		size_b;

	size_a = stack_size(ps->stack_a);
	size_b = stack_size(ps->stack_b);
	if (stack->above_median)
		cost_a = stack->index;
	else
		cost_a = size_a - stack->index;
	if (stack->target_node->above_median)
		cost_b = stack->target_node->index;
	else
		cost_b = size_b - stack->target_node->index;
	if (stack->above_median == stack->target_node->above_median)
	{
		if (cost_a >= cost_b)
			stack->push_cost = cost_a;
		else
			stack->push_cost = cost_b;
	}
	else
		stack->push_cost = cost_a + cost_b;
}

static void	set_index(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

static void	set_median(t_stack *stack)
{
	int		size;
	int		median;

	size = stack_size(stack);
	if (size % 2 == 0)
		median = size / 2;
	else
		median = size / 2 + 1;
	while (stack)
	{
		if (stack->index < median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}

void	set_cost(t_push_swap *ps, t_stack *stack)
{
	t_stack		*temp;

	temp = stack;
	while (temp)
	{
		calculate_cost(ps, temp);
		temp = temp->next;
	}
}

void	set_all(t_push_swap *ps)
{
	set_index(ps->stack_a);
	set_index(ps->stack_b);
	set_median(ps->stack_a);
	set_median(ps->stack_b);
}
