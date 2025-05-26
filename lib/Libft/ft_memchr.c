/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:32:51 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/11 15:38:26 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	temp_c;
	int				i;

	temp_s = (unsigned char *) s;
	temp_c = (unsigned char) c;
	i = 0;
	while (n--)
	{
		if (temp_s[i] == temp_c)
			return ((void *) &temp_s[i]);
		i++;
	}
	return (NULL);
}
