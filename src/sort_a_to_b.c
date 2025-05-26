/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:04 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:04 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_cheapest(t_stack *stack)
{
	t_stack		*cheapest_node;
	int			min_cost;

	cheapest_node = stack;
	min_cost = stack->push_cost;
	while (stack)
	{
		if (stack->push_cost < min_cost)
		{
			min_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

static void	set_top(t_push_swap *ps, t_stack *node_a, t_stack *node_b)
{
	if ((node_a->above_median == node_b->above_median) && (node_a->value
			!= ps->stack_a->value || node_b->value != ps->stack_b->value))
	{
		if (node_a->above_median == 1)
			rr(ps);
		else
			rrr(ps);
	}
	else
	{
		if (node_a->value != ps->stack_a->value)
		{
			if (node_a->above_median == 1)
				ra(ps, 1);
			else
				rra(ps, 1);
		}
		if (node_b->value != ps->stack_b->value)
		{
			if (node_b->above_median == 1)
				rb(ps, 1);
			else
				rrb(ps, 1);
		}
	}
}

void	a_to_b(t_push_swap *ps)
{
	t_stack		*cheapest;
	t_stack		*target;

	cheapest = find_cheapest(ps->stack_a);
	target = cheapest->target_node;
	while (cheapest->value != ps->stack_a->value
		|| target->value != ps->stack_b->value)
	{
		set_top(ps, cheapest, target);
		set_all(ps);
	}
	pb(ps);
}
