/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:08:47 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/27 12:58:37 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, len + 1);
	ft_strlcat(new_s, s2, len + 1);
	return (new_s);
}
