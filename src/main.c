/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:02:28 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:02:28 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_push_swap	*ps_init(void)
{
	t_push_swap	*ps;

	ps = NULL;
	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		print_error();
	ft_memset(ps, 0, sizeof(t_push_swap));
	return (ps);
}

static void	data_init(t_push_swap *ps, int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		free(ps);
		print_error();
	}
	ft_memset(data, 0, sizeof(data));
	ps->data = data;
	data->input = argv;
	data->argc = argc;
	if (!argv[0])
	{
		free(data);
		free(ps);
		print_error();
	}
	check_duplicate(ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = NULL;
	if (argc == 1)
		return (1);
	ps = ps_init();
	data_init(ps, argc, argv + 1);
	stack_init(ps);
	sort_stack(ps);
	free(ps->data->numbers);
	free(ps->data);
	free_stack(ps->stack_a);
	free_stack(ps->stack_b);
	free(ps);
	return (0);
}
