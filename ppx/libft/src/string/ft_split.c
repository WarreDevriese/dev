/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:36:02 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 15:25:29 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **split, size_t i)
{
	while (i)
		free(split[--i]);
	free(split);
}

static char	**ft_fill_split(char **split, char const *s, char c,
		size_t word_count)
{
	char const	*start;
	size_t		i;

	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		split[i] = ft_substr(start, 0, s - start);
		if (!split[i])
		{
			ft_free_split(split, i);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	split = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_fill_split(split, s, c, word_count);
	return (split);
}
