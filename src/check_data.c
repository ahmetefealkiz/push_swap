/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:02:18 by aalkiz            #+#    #+#             */
/*   Updated: 2025/04/16 14:02:18 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_data_free(t_push_swap *ps, char **str)
{
	free_2d(str);
	free(ps->data->numbers);
	free(ps->data);
	free(ps);
	print_error();
}

static void	check_digit(t_push_swap *ps, char **str)
{
	int		i;
	int		j;

	i = 0;
	if (str[0] == NULL)
		check_data_free(ps, str);
	while (str[i])
	{
		j = 0;
		if ((str[i][j] == '+' || str[i][j] == '-') && ft_isdigit(str[i][j + 1])
			&& str[i][j + 1])
			j++;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				check_data_free(ps, str);
			j++;
		}
		i++;
	}
}

static void	check_int(t_push_swap *ps, char **str)
{
	int		i;
	long	temp;

	i = 0;
	while (str[i])
	{
		check_long(ps, str[i], str);
		temp = atol(str[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			free_2d(str);
			free(ps->data->numbers);
			free(ps->data);
			free(ps);
			print_error();
		}
		i++;
	}
}

static void	numbers_init(t_push_swap *ps)
{
	char	**input_splitted;
	int		*numbers;
	int		size;
	int		i;
	int		added_numbers;

	size = count_input(ps);
	numbers = alloc_numbers(ps, size);
	i = 0;
	added_numbers = 0;
	ps->data->numbers = numbers;
	ps->data->size = size;
	while (ps->data->input[i])
	{
		input_splitted = ft_split(ps->data->input[i], ' ');
		check_digit(ps, input_splitted);
		check_int(ps, input_splitted);
		added_numbers = add_input(ps, input_splitted, added_numbers);
		free_2d(input_splitted);
		i++;
	}
}

void	check_duplicate(t_push_swap *ps)
{
	int		i;
	int		j;

	numbers_init(ps);
	i = 0;
	while (ps->data->size - 1 > i)
	{
		j = i + 1;
		while (ps->data->size > j)
		{
			if (ps->data->numbers[i] == ps->data->numbers[j])
			{
				free(ps->data->numbers);
				free(ps->data);
				free(ps);
				print_error();
			}
			j++;
		}
		i++;
	}
}
