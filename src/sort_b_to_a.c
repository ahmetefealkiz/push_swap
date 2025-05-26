/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:08 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:08 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack		*min_node;
	t_stack		*temp;
	int			min_value;

	if (stack_size(stack) == 1)
		return (stack);
	min_value = INT_MAX;
	temp = stack;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_node = temp;
			min_value = temp->value;
		}
		temp = temp->next;
	}
	return (min_node);
}

t_stack	*find_target_b(t_stack *stack, int value)
{
	t_stack		*target;
	t_stack		*temp;
	int			target_value;
	int			control;

	control = 0;
	target_value = INT_MAX;
	temp = stack;
	while (temp)
	{
		if ((temp->value) > value && (temp->value) <= target_value)
		{
			target = temp;
			target_value = temp->value;
			control = 1;
		}	
		temp = temp->next;
	}
	if (control == 0)
		target = find_min(stack);
	return (target);
}

void	prep_a(t_push_swap *ps, t_stack *stack)
{
	if (stack->target_node->above_median)
		ra(ps, 1);
	else
		rra(ps, 1);
}

void	set_target_b(t_push_swap *ps)
{
	t_stack		*temp;

	temp = ps->stack_b;
	while (temp)
	{
		temp->target_node = find_target_b(ps->stack_a, temp->value);
		temp = temp->next;
	}
}

void	b_to_a(t_push_swap *ps)
{
	while (stack_size(ps->stack_b) != 0)
	{
		set_target_b(ps);
		set_all(ps);
		while (ps->stack_a->value != ps->stack_b->target_node->value)
		{
			prep_a(ps, ps->stack_b);
			set_all(ps);
		}
		pa(ps);
	}
}
