/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:26:23 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 15:38:11 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (NULL);
	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		index--;
	}
	return (0);
}
