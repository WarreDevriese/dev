/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:53:42 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/25 17:15:27 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			sublen;
	unsigned int	strlen;

	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	if (start + len > strlen)
		sublen = strlen - start;
	else
		sublen = len;
	substr = (char *)malloc((sublen + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, sublen + 1);
	return (substr);
}
