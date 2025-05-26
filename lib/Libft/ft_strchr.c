/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:44:19 by aalkiz            #+#    #+#             */
/*   Updated: 2024/10/31 20:26:48 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*result;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
		{
			result = (char *)&s[i];
			return (result);
		}
		i++;
	}
	result = NULL;
	return (result);
}
