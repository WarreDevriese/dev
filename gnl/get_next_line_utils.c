/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:25:06 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/13 09:57:29 by wdevries         ###   ########.fr       */
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

char	*free_line(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (NULL);
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
	char	*p_start;

	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p_start = p;
	while (s && *s)
		*p++ = *s++;
	*p = '\0';
	return (p_start);
}

char	*ft_strjoin(char const *line_parse, char const *buffer)
{
	size_t	len;
	char	*new_s;
	char	*new_s_start;

	if (!line_parse && !buffer)
		return (NULL);
	len = ft_strlen(line_parse) + ft_strlen(buffer);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	new_s_start = new_s;
	while (line_parse && *line_parse)
		*new_s++ = *line_parse++;
	while (buffer && *buffer)
		*new_s++ = *buffer++;
	*new_s = '\0';
	return (new_s_start);
}
