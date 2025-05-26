/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:15 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:15 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_for_three(t_push_swap *ps)
{
	int		number_1;
	int		number_2;
	int		number_3;

	number_1 = ps->stack_a->value;
	number_2 = ps->stack_a->next->value;
	number_3 = ps->stack_a->next->next->value;
	if (number_1 > number_2 && number_1 < number_3 && number_2 < number_3)
		sa(ps, 1);
	else if (number_1 > number_2 && number_1 > number_3 && number_2 < number_3)
		ra(ps, 1);
	else if (number_1 < number_2 && number_1 > number_3 && number_2 > number_3)
		rra(ps, 1);
	else if (number_1 > number_2 && number_1 > number_3 && number_2 > number_3)
	{
		sa(ps, 1);
		rra(ps, 1);
	}
	else if (number_1 < number_2 && number_1 < number_3 && number_2 > number_3)
	{
		sa(ps, 1);
		ra(ps, 1);
	}
}

void	order_stack_a(t_push_swap *ps)
{
	t_stack		*max_node;

	max_node = find_max(ps->stack_a);
	while (ps->stack_a->value != max_node->value)
	{
		if (max_node->above_median)
			ra(ps, 1);
		else
			rra(ps, 1);
	}
	ra(ps, 1);
}

void	sort_stack(t_push_swap *ps)
{
	if (!is_sorted(ps->stack_a))
	{
		if (stack_size(ps->stack_a) == 2)
			sa(ps, 1);
		else if (stack_size(ps->stack_a) == 3)
			sort_for_three(ps);
		else
		{
			if (stack_size(ps->stack_a) > 4)
				pb(ps);
			pb(ps);
			while (stack_size(ps->stack_a) > 3)
			{
				set_all(ps);
				set_target_a(ps);
				set_cost(ps, ps->stack_a);
				a_to_b(ps);
			}
			sort_for_three(ps);
			order_stack_b(ps);
			set_all(ps);
			b_to_a(ps);
			order_stack_a(ps);
		}
	}
}
