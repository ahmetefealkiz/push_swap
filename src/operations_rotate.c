/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:02:53 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:02:53 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_push_swap *ps, int print)
{
	t_stack		*temp;
	t_stack		*last;

	if (stack_size(ps->stack_a) > 1)
	{
		last = stack_last(ps->stack_a);
		temp = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		last->next = temp;
		temp->next = NULL;
	}
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_push_swap *ps, int print)
{
	t_stack		*temp;
	t_stack		*last;

	if (stack_size(ps->stack_b) > 1)
	{
		last = stack_last(ps->stack_b);
		temp = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		last->next = temp;
		temp->next = NULL;
	}
	if (print == 1)
		ft_printf("rb\n");
}

void	rr(t_push_swap *ps)
{
	ra(ps, 0);
	rb(ps, 0);
	ft_printf("rr\n");
}
