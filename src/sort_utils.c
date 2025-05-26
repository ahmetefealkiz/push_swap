/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:11 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:11 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack	*stack)
{
	int		temp;

	if (stack)
		temp = stack->value;
	while (stack)
	{
		if (temp > stack->value)
			return (0);
		temp = stack->value;
		stack = stack->next;
	}
	return (1);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack		*max_node;
	t_stack		*temp;
	int			max_value;

	if (stack_size(stack) == 1)
		return (stack);
	max_value = INT_MIN;
	temp = stack;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_node = temp;
			max_value = temp->value;
		}
		temp = temp->next;
	}
	return (max_node);
}

t_stack	*find_target(t_stack *stack, int value)
{
	t_stack		*target;
	t_stack		*temp;
	int			target_value;
	int			control;

	control = 0;
	target_value = INT_MIN;
	temp = stack;
	while (temp)
	{
		if ((temp->value) < value && (temp->value) > target_value)
		{
			target = temp;
			target_value = temp->value;
			control = 1;
		}	
		temp = temp->next;
	}
	if (control == 0)
		target = find_max(stack);
	return (target);
}

void	set_target_a(t_push_swap *ps)
{
	t_stack		*temp;

	temp = ps->stack_a;
	while (temp)
	{
		temp->target_node = find_target(ps->stack_b, temp->value);
		temp = temp->next;
	}
}

void	order_stack_b(t_push_swap *ps)
{
	t_stack		*max_node;

	max_node = find_max(ps->stack_b);
	while (ps->stack_b->value != max_node->value)
	{
		if (max_node->above_median)
			rb(ps, 1);
		else
			rrb(ps, 1);
	}
}
