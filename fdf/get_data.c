/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/29 14:04:08 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_dimensions(char	*file, t_map *dimensions)
{
	int		fd;
	char	*line;
	size_t	temp_width;

	dimensions->width = 0;
	dimensions->height = 0;
	ft_open_rdonly(file, &fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_width = ft_word_count(line, ' ');
		if (temp_width > dimensions->width)
			dimensions->width = temp_width;
		dimensions->height++;
		free(line);
	}
	ft_close(fd);
}

static void		allocate_data_array(size_t width, size_t height, int ***data)
{
	size_t	i;

	*data = (int **)malloc((height) * sizeof(int *));
	if (!*data)
	{
		perror("Error malloc 2D array");
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		(*data)[i] = (int *)malloc(width * sizeof(int));
		if (!(*data)[i])
		{
			while (i)
				free((*data)[--i]);
			free(*data);
			perror("Error malloc 2D array");
			exit(1);
		}
		i++;
	}
}

static void		populate_data_array(int fd, size_t width, size_t height, int ***data)
{
	size_t		row;
	size_t		column;
	char	*line;
	char	**words;

	row = 0;
	while (row < height)
	{
		line = get_next_line(fd);
		words = ft_split(line, ' ');
		column = 0;
		while (column < width)
		{
			(*data)[row][column] = ft_atoi(words[column]);
			free(words[column]);
			column++;
		}
		free(line);
		free(words);
		row++;
	}
}

void		get_data(char *file, int ***data)
{
	int		fd;
	t_map	dimensions;

	get_dimensions(file, &dimensions);
	allocate_data_array(dimensions.width, dimensions.height, data);
	ft_open_rdonly(file, &fd);
	populate_data_array(fd, dimensions.width, dimensions.height, data);
	ft_close(fd);
}
