/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:07:24 by aalkiz            #+#    #+#             */
/*   Updated: 2024/10/23 19:34:01 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;

	joinstr = ft_calloc (ft_strlen (s1) + ft_strlen (s2) + 1, sizeof(char));
	if (!joinstr)
		return (NULL);
	ft_memcpy (joinstr, s1, ft_strlen(s1));
	ft_memcpy (joinstr + ft_strlen(s1), s2, ft_strlen(s2));
	return (joinstr);
}
