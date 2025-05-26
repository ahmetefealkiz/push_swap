/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkiz <aalkiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:11:58 by aalkiz            #+#    #+#             */
/*   Updated: 2024/11/05 00:58:35 by aalkiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s && s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	*ft_free_words(char **words, size_t w)
{
	size_t	i;

	i = 0;
	while (i < w)
	{
		free (words[i]);
		i++;
	}
	free (words);
	return (NULL);
}

static char	**ft_fill_words(char **words, char const *s, char c)
{
	size_t	i;
	size_t	w;
	size_t	start;

	i = 0;
	w = 0;
	start = 0;
	while (s[i])
	{
		if ((s[i + 1] == c && s[i] != c) || (s[i] != c && !s[i + 1]))
		{
			words[w] = ft_substr(s, start, (i - start) + 1);
			if (!words[w])
				return (ft_free_words(words, w));
			w++;
		}
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;

	if (!s)
		return (NULL);
	str_split = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!str_split)
		return (NULL);
	str_split = ft_fill_words(str_split, s, c);
	return (str_split);
}
