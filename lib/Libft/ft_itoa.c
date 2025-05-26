/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:07:22 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/05 02:25:53 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_int(int const n)
{
	size_t	count;
	int		nbr;

	count = 1;
	if (n < 0)
	{
		nbr = -1 * n;
		count++;
	}
	else
		nbr = n;
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		nbr;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr = n;
	len = ft_count_int(nbr);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
		nbr = -1 * n;
	while (nbr != 0)
	{
		res[len - 1] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	return (res);
}
