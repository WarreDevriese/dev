/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/01 13:32:50 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_dimensions(char	*file, t_dimensions *map)
{
	int		fd;
	char	*line;
	size_t	temp_width;

	map->width = 0;
	map->height = 0;
	ft_open_rdonly(file, &fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_width = ft_word_count(line, ' ');
		if (temp_width > map->width)
			map->width = temp_width;
		map->height++;
		free(line);
	}
	ft_close(fd);
}

static void		allocate_data_array(size_t width, size_t height, t_iso ***data_array)
{
	size_t	i;

	*data_array = (t_iso **)malloc((height) * sizeof(t_iso *));
	if (!*data_array)
	{
		perror("Error malloc data_array");
		exit(1);
	}
	i = 0;
	while (i < height)
	{
		(*data_array)[i] = (t_iso *)malloc(width * sizeof(t_iso));
		if (!(*data_array)[i])
		{
			while (i)
				free((*data_array)[--i]);
			free(*data_array);
			perror("Error malloc data_array");
			exit(1);
		}
		i++;
	}
}

static void		populate_data_array(int fd, t_dimensions map, t_math angle_values, t_iso ***data_array)
{
	size_t		row;
	size_t		column;
	char	*line;
	char	**words;

	row = 0;
	while (row < map.height)
	{
		line = get_next_line(fd);
		words = ft_split(line, ' ');
		column = 0;
		while (column < map.width)
		{
			(*data_array)[row][column].z = ft_atoi(words[column]);
			(*data_array)[row][column].x = column - ((*data_array)[row][column].z * angle_values.cos30);
			(*data_array)[row][column].y = row + ((column + (*data_array)[row][column].z) * angle_values.sin30);
			free(words[column]);
			column++;
		}
		free(line);
		free(words);
		row++;
	}
}

t_iso		**get_data(char *file, t_dimensions *map)
{
	int		fd;
	t_iso	**data_array;
	t_math	angle_values;

	get_dimensions(file, map);
	allocate_data_array(map->width, map->height, &data_array);
	ft_open_rdonly(file, &fd);
	angle_values.sin30 = sin(M_PI / 6);
	angle_values.cos30 = cos(M_PI / 6);
	populate_data_array(fd, *map, angle_values, &data_array);
	ft_close(fd);
	return (data_array);
}
