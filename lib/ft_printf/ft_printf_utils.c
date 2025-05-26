/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:10:44 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/23 01:18:06 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_pf(char c, int count)
{
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putstr_pf(char *s, int count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		count = ft_putstr_pf("(null)", count);
		return (count);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (count + i);
}

int	ft_putnbr_pf(int n, int count)
{
	if (n == -2147483648)
	{
		count = ft_putchar_pf('-', count);
		count = ft_putchar_pf('2', count);
		count = ft_putnbr_pf(147483648, count);
	}
	else if (n < 0)
	{
		count = ft_putchar_pf('-', count);
		count = ft_putnbr_pf(-n, count);
	}
	else if (n > 9)
	{
		count = ft_putnbr_pf(n / 10, count);
		count = ft_putnbr_pf(n % 10, count);
	}
	else if (n <= 9)
		count = ft_putchar_pf(n + 48, count);
	return (count);
}

int	ft_putnbru(unsigned int u, int count)
{
	if (u > 9)
	{
		count = ft_putnbr_pf(u / 10, count);
		count = ft_putnbr_pf(u % 10, count);
	}
	else if (u <= 9)
		count = ft_putchar_pf(u + 48, count);
	return (count);
}

int	ft_puthex(unsigned long nbr, char c, int count)
{
	char			*s1;
	char			*s2;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	if (nbr == 0)
	{
		count = ft_putchar_pf('0', count);
		return (count);
	}
	else if (nbr > 15)
	{
		count = ft_puthex(nbr / 16, c, count);
		count = ft_puthex(nbr % 16, c, count);
	}
	else if (nbr <= 15)
	{
		if (c == 'x')
			count = ft_putchar_pf(s1[nbr], count);
		if (c == 'X')
			count = ft_putchar_pf(s2[nbr], count);
	}
	return (count);
}
