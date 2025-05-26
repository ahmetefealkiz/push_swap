/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:02:47 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:02:47 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_push_swap *ps, int print)
{
	t_stack		*temp;
	t_stack		*last;

	if (stack_size(ps->stack_a) > 1)
	{
		last = stack_last(ps->stack_a);
		temp = ps->stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next = NULL;
		last->next = ps->stack_a;
		ps->stack_a = last;
	}
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_push_swap *ps, int print)
{
	t_stack		*temp;
	t_stack		*last;

	if (stack_size(ps->stack_b) > 1)
	{
		last = stack_last(ps->stack_b);
		temp = ps->stack_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next = NULL;
		last->next = ps->stack_b;
		ps->stack_b = last;
	}
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_push_swap *ps)
{
	rra(ps, 0);
	rrb(ps, 0);
	ft_printf("rrr\n");
}
