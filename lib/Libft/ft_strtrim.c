/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:41:25 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/04 20:13:17 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	if (s1_len == 0)
		return (ft_strdup(""));
	while (check_set(s1[i], set))
		i++;
	if (i >= s1_len)
		return (ft_strdup(""));
	while (check_set(s1[s1_len - 1], set))
		s1_len--;
	s1_len -= i;
	trimstr = ft_calloc(s1_len + 1, sizeof(char));
	if (!trimstr)
		return (NULL);
	ft_memcpy(trimstr, s1 + i, s1_len);
	return (trimstr);
}
