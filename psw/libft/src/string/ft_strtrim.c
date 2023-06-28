/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:24:47 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/15 08:58:25 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start_s;
	char	*end_s;
	char	*new_s;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	start_s = (char *)s1;
	end_s = (char *)s1;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			end_s = (char *)s1 + 1;
		s1++;
	}
	len = end_s - start_s;
	new_s = ft_substr(start_s, 0, len);
	return (new_s);
}
