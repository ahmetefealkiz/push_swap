/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:03:19 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:03:19 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	create_stack(t_push_swap *ps)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (i < ps->data->size)
	{
		temp = stack_new(ps, ps->data->numbers[i]);
		stack_add_back(&ps->stack_a, temp);
		i++;
	}
}

void	stack_init(t_push_swap *ps)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	ps->stack_a = a;
	ps->stack_b = b;
	create_stack(ps);
}
