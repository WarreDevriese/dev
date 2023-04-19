/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:24:47 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/06 14:59:07 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start_s;
	char	*end_s;
	char	*new_s;
	size_t	len;

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
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (0);
	ft_memcpy(new_s, start_s, len);
	new_s[len] = '\0';
	return (new_s);
}
