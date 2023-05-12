/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:25:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/12 10:54:38 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*p;

	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, len + 1);
	return (p);
}

char	*ft_strjoin(char const *line_parse, char const *buffer)
{
	size_t	len;
	char	*new_s;

	if (!line_parse && !buffer)
		return (NULL);
	len = ft_strlen(line_parse) + ft_strlen(buffer);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, line_parse, len + 1);
	ft_strlcpy(new_s + ft_strlen(line_parse), buffer, len + 1);
	return (new_s);
}
