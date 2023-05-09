/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:24:40 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/08 11:29:52 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char **line_parse)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (!ft_strchr(*line_parse, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*line_parse, buffer);
		free(*line_parse);
		*line_parse = temp;
	}
	free(buffer);
	return (0);
}

static char	*ft_extract_nl(char **line_parse, char *nl_position)
{
	char	*new_line_parse;
	char	*line_return;

	line_return = (char *)malloc
		((nl_position - *line_parse + 2) * sizeof(char));
	if (!line_return)
	{
		free(*line_parse);
		line_parse = NULL;
		return (NULL);
	}
	ft_strlcpy(line_return, *line_parse, nl_position - *line_parse + 2);
	new_line_parse = ft_strdup(nl_position + 1);
	free(*line_parse);
	*line_parse = new_line_parse;
	return (line_return);
}

static char	*ft_extract_eof(char **line_parse)
{
	char	*line_return;

	line_return = (char *)malloc
		((ft_strlen(*line_parse) + 1) * sizeof(char));
	if (!line_return)
	{
		free(*line_parse);
		*line_parse = NULL;
		return (NULL);
	}
	ft_strlcpy(line_return, *line_parse, ft_strlen(*line_parse) + 1);
	free(*line_parse);
	*line_parse = NULL;
	return (line_return);
}

static char	*ft_extract(char **line_parse)
{
	char	*nl_position;
	char	*line_return;

	nl_position = ft_strchr(*line_parse, '\n');
	if (nl_position)
		line_return = ft_extract_nl(line_parse, nl_position);
	else
		line_return = ft_extract_eof(line_parse);
	return (line_return);
}

char	*get_next_line(int fd)
{
	static char	*line_parse;
	char		*line_return;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (ft_read(fd, &line_parse) == -1)
	{
		free(line_parse);
		line_parse = NULL;
		return (NULL);
	}
	if (line_parse && *line_parse == 0)
	{
		free(line_parse);
		line_parse = NULL;
		return (NULL);
	}
	line_return = ft_extract(&line_parse);
	return (line_return);
}
