/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:02:57 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:02:57 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_push_swap *ps, int print)
{
	t_stack	*temp;

	if (stack_size(ps->stack_a) > 1)
	{
		temp = ps->stack_a->next;
		ps->stack_a->next = ps->stack_a->next->next;
		temp->next = ps->stack_a;
		ps->stack_a = temp;
	}
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_push_swap *ps, int print)
{
	t_stack	*temp;

	if (stack_size(ps->stack_b) > 1)
	{
		temp = ps->stack_b->next;
		ps->stack_b->next = ps->stack_b->next->next;
		temp->next = ps->stack_b;
		ps->stack_b = temp;
	}
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_push_swap *ps)
{
	sa(ps, 0);
	sb(ps, 0);
	ft_printf("ss\n");
}
