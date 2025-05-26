/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:27:28 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/17 01:37:31 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_long(t_push_swap *ps, char *str, char **free_str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 12)
	{
		free_2d(free_str);
		free(ps->data->numbers);
		free(ps->data);
		free(ps);
		print_error();
	}
}

int	*alloc_numbers(t_push_swap *ps, int size)
{
	int	*numbers;

	numbers = ft_calloc(size, sizeof(int));
	if (!numbers)
	{
		free(ps->data);
		free(ps);
		print_error();
	}
	return (numbers);
}

int	count_spilted_input(int added_numbers, char **input_splitted)
{
	int	i;

	i = 0;
	while (input_splitted[i])
		i++;
	return (i + added_numbers);
}

int	count_input(t_push_swap *ps)
{
	int		i;
	int		added_numbers;
	char	**input_splitted;

	i = 0;
	input_splitted = NULL;
	added_numbers = 0;
	while (ps->data->input[i])
	{
		input_splitted = ft_split(ps->data->input[i], ' ');
		if (!input_splitted)
		{
			free(ps->data);
			free(ps);
			print_error();
		}
		added_numbers = count_spilted_input(added_numbers, input_splitted);
		free_2d(input_splitted);
		i++;
	}
	return (added_numbers);
}

int	add_input(t_push_swap *ps, char **input_splitted, int added_numbers)
{
	int	i;

	i = 0;
	while (input_splitted[i])
	{
		ps->data->numbers[added_numbers + i] = atoi(input_splitted[i]);
		i++;
	}
	return (i + added_numbers);
}
