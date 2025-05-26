/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:18:33 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/15 02:03:31 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	if (!dst && !src)
		return (NULL);
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	while (n--)
		*(temp_dst++) = *(temp_src++);
	return (dst);
}
