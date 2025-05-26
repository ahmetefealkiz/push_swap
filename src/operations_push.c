/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:02:43 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:02:43 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_push_swap *ps)
{
	t_stack		*temp;

	if (stack_size(ps->stack_b) > 0)
	{
		temp = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		temp->next = ps->stack_a;
		ps->stack_a = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_push_swap *ps)
{
	t_stack		*temp;

	if (stack_size(ps->stack_a) > 0)
	{
		temp = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		temp->next = ps->stack_b;
		ps->stack_b = temp;
	}
	ft_printf("pb\n");
}
