/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:17:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/09 13:41:16 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(char const *s, char c)
{
	size_t		count;
	char const	*start;

	count = 0;
	start = s;
	while (*s)
	{
		if (*s != c && (s == start || *(s - 1) == c))
			count++;
		s++;
	}
	return (count);
}
