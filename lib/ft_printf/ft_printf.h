/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 21:06:18 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/29 18:00:40 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_pf(char c, int count);
int	ft_putstr_pf(char *s, int count);
int	ft_putnbr_pf(int n, int count);
int	ft_putnbru(unsigned int u, int count);
int	ft_puthex(unsigned long nbr, char c, int count);

#endif
