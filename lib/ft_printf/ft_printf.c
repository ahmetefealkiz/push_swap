/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:10:53 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/23 01:17:29 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(void *add, int count)
{
	unsigned long	u;

	if (add == NULL)
	{
		count = ft_putstr_pf("(nil)", count);
		return (count);
	}
	u = (unsigned long)add;
	count = ft_putstr_pf("0x", count);
	count = ft_puthex(u, 'x', count);
	return (count);
}

static int	ft_typecheck(char c, va_list list, int count)
{
	if (c == 'c')
		count = ft_putchar_pf(va_arg(list, int), count);
	else if (c == 's' )
		count = ft_putstr_pf(va_arg(list, char *), count);
	else if (c == 'p')
		count = ft_putptr(va_arg(list, void *), count);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_pf(va_arg(list, int), count);
	else if (c == 'u')
		count = ft_putnbru(va_arg(list, unsigned int), count);
	else if (c == 'x')
		count = ft_puthex(va_arg(list, unsigned int), c, count);
	else if (c == 'X')
		count = ft_puthex(va_arg(list, unsigned int), c, count);
	else if (c == '%')
		count = ft_putchar_pf('%', count);
	else
		return (count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	va_start(list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = ft_typecheck(format[i], list, count);
		}
		else
			count = ft_putchar_pf(format[i], count);
		i++;
	}
	va_end(list);
	return (count);
}
