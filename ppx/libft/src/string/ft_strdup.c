/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:38:20 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 15:26:28 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*p;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s, len + 1);
	return (p);
}
