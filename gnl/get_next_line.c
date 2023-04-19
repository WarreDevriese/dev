/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/14 15:20:35 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_read_line(int fd, char **line_to_parse)
{
	char	*buffer;
	char	*buffer_strjoin;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (!ft_strchr(*line_to_parse, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		buffer_strjoin = ft_strjoin(*line_to_parse, buffer);
		free(*line_to_parse);
		*line_to_parse = buffer_strjoin;
	}
	free(buffer);
	return (0);
}

static char	*ft_extract_line(char **line_to_parse)
{
	char	*new_line_to_parse;
	char	*newline_position;
	char	*line_to_return;

	newline_position = ft_strchr(*line_to_parse, '\n');
	if (newline_position)
	{
		line_to_return = malloc(newline_position - *line_to_parse + 2);
		if (!line_to_return)
			return (NULL);
		ft_strlcpy(line_to_return, *line_to_parse, newline_position
			- *line_to_parse + 2);
		new_line_to_parse = ft_strdup(newline_position + 1);
		free(*line_to_parse);
		*line_to_parse = new_line_to_parse;
	}
	else
	{
		line_to_return = malloc(ft_strlen(*line_to_parse) + 1);
		ft_strlcpy(line_to_return, *line_to_parse, ft_strlen(*line_to_parse)
			+ 1);
		free(*line_to_parse);
		*line_to_parse = NULL;
	}
	return (line_to_return);
}

char	*get_next_line(int fd)
{
	static char	*line_to_parse;
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	if (ft_read_line(fd, &line_to_parse) == -1)
	{
		free(line_to_parse);
		line_to_parse = NULL;
		return (NULL);
	}
	if (line_to_parse && *line_to_parse == 0)
	{
		free(line_to_parse);
		line_to_parse = NULL;
		return (NULL);
	}
	line_to_return = ft_extract_line(&line_to_parse);
	return (line_to_return);
}
